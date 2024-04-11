#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	char A[n][m];
	int stx, sty, endx, endy;
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            if(A[i][j] == 'S')
            {
                stx = i;
                sty = j;
            }
            if(A[i][j] == 'E')
            {
                endx = i;
                endy = j;
            }
        }
    }
    string s;
    cin >> s;
    vector <char> op = {'U','D', 'L', 'R'};
    vector <int> a(4);
    for(int i = 0; i < 4; i++)
    {
        a[i] = i;
    }
    int ans = 0;
    do{
        bool fl = 1;
        int stx1 = stx;
        int sty1 = sty;
        for(int i = 0; i < s.size(); i++)
        {
            int ind = s[i] - '0';
            if(op[a[ind]] == 'U')
            {
                stx1--;
            }
            else if(op[a[ind]] == 'L')
            {
                sty1--;
            }
            else if(op[a[ind]] == 'D')
            {
                stx1++;
            }
            else
            {
                sty1++;
            }
            if(stx1 < 0 || stx1 >= n || sty1 < 0 || sty1 >= m || A[stx1][sty1] == '#')
            {
                fl = 0;
                break;
            }
            if(A[stx1][sty1] == 'E')
            {
                break;
            }
        }

        if(fl && A[stx1][sty1] != 'E')
        {
            fl = 0;
        }
        ans += fl;
    }while(next_permutation(a.begin(), a.end()));
    cout << ans;
	return 0;
}