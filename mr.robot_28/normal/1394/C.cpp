#include<bits/stdc++.h>
 
using namespace std;


int lx = 1e9;
int rx = -1e9;
int ly = 1e9;
int ry = -1e9;
int lz = 1e9;
int rz = -1e9;
int stx = 0, sty = 0, stz = 0;
bool check(int a)
{
	return lx + a + a >= rx && lx - ry + a + a + a >= rz && ry - a * 2 <= ly;
}
int calc()
{
	int l = 0, r = lz - (lx - ry);
	if(check(r) == 0)
	{
		return 1e9;
	}
	while(r > l)
	{
		int midd = (r + l) / 2;
		if(check(midd))
		{
			r = midd;
		}
		else
		{
			l = midd + 1;
		}
	}
	return l;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int x = 0, y = 0;
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == 'B')
			{
				x++;
			}
			else
			{
				y++;
			}
		}
		lx = min(lx, x);
		rx = max(rx, x);
		ly = min(ly, y);
		ry = max(ry, y);
		lz = min(lz, x - y);
		rz = max(rz, x - y);
	}
	int ans = 1e9;
	for(int i = 1; i <= 6; i++)
	{
		int v = calc();
		if(v < ans)
		{
			ans = v;
			stx = lx + v;
			sty = ry - v;
			stz = stx - sty;
		}
		int Lx = ly, Rx = ry, Ly = -rz, Ry = -lz, Lz = lx ,Rz = rx;
        lx = Lx, rx = Rx, ly = Ly, ry = Ry, lz = Lz, rz = Rz;
		int Stx = sty, Sty = -stz, Stz = stx;
		stx = Stx;
		sty = Sty;
		stz = Stz;
	}
	cout << ans << endl;
	for(int i = 0; i < stx; i++)
	{
		cout << "B";
	}
	for(int i = 0; i < sty; i++)
	{
		cout << "N";
	}
	return 0;
}