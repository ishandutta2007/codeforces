#include <bits/stdc++.h>
using namespace std;

const int n = 7;
const int mod = 1000000007;

int w[n];
int res[n][128][128],test[128][128],ways[128];
int tr [n][128][128][17];

int mul (int x, int y) { return (long long)x * y % mod; }
void add (int &x, int y) { x+= y; if (x>=mod) x-=mod; }

int main(){
	for (int i=0; i<n; i++)
		cin >> w[i];
	for (int o=0; o<n; o++) if (w[o]){
		int l = o+1;
		for (int up = 0; up < (1<<l); up++)
			for (int bot=0; bot < (1<<l); bot++)
				for (int mid=0; mid < (1<<(l-1)); mid++){
					bool f = true;
					for (int i=0; i<l; i++) if ((up&bot)&(1<<i)){
						bool left = (i==0) || (mid & (1<<(i-1)));
						bool right= (i==l-1) || (mid & (1<<i));
						if (left && right){
							f = false;
							break;
						}
					}
					if (f)
						tr[o][up][bot][0]++;
				}
		for (int k=1; (1<<k)<=w[o]; k++)
			for (int up=0; up<(1<<l); up++)
				for (int mid=0; mid<(1<<l); mid++)
					for (int bot=0; bot<(1<<l); bot++)
						add(tr[o][up][bot][k], mul(tr[o][up][mid][k-1], tr[o][mid][bot][k-1]));
		bool init = false;
		for (int bit=0; (1<<bit)<=w[o]; bit++) if (w[o] & (1<<bit)){
			if (init == false){
				for (int up=0; up<(1<<l); up++)
					for (int bot=0; bot<(1<<l); bot++)
						res[o][up][bot] = tr[o][up][bot][bit];
				init = true;
			}else{
				memset(test, 0, sizeof test);
				for (int up=0; up<(1<<l); up++)
					for (int bot=0; bot<(1<<l); bot++)
						for (int mid=0; mid<(1<<l); mid++)
							add(test[up][bot], mul(res[o][up][mid], tr[o][mid][bot][bit]));
				for (int up=0; up<(1<<l); up++)
					for (int bot=0; bot<(1<<l); bot++)
						res[o][up][bot] = test[up][bot];
			}
		}
	}
	int last = 0;
	ways[0] = 1;
	for (int o=0; o<n; o++) if (w[o] != 0){
		for (int mask=0; mask<(1<<last); mask++){
			int shif =
			ways[mask + ((((1<<(o+1-last))-1))<<last)] = ways[mask];
			ways[mask] = 0;
		}
		vector<int> temp(1<<(o+1), 0);
		for (int up=0; up<(1<<(o+1)); up++)
			for (int bot=0; bot<(1<<(o+1)); bot++)
				add(temp[bot], mul(ways[up], res[o][up][bot]));
		for (int mask=0; mask<(1<<(o+1)); mask++)
			ways[mask] = temp[mask];
		last = o+1;
	}
	for (int i=n-1; i>=0; i--) if (w[i]){
		cout << ways[(1<<(i+1))-1] << endl;
		break;
	}
	return 0;
}