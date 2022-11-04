#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000+10;

int n;
int a[MAXN],sum[MAXN];

int get (int l, int r){
	return sum[r+1] - sum[l];
}

int go (int t){
	int i = 0;
	int s0 = 0, s1 = 0;
	int last = -1;
	while (i<n){
		int lo = i, hi = n-1, ans = -1;
		while (lo <= hi){
			int mid = (lo+hi)/2;
			int r1 = get(i,mid);
			int r2 = mid-i+1-r1;
			if (max(r1,r2)>=t){
				ans = mid;
				hi = mid-1;
			}
			else
				lo = mid+1;
		}
		if (ans == -1)
			return -1;
		int r1 = get(i,ans);
		int r2 = ans-i+1-r1;
		if (r1==t) { s0++; last = 0; }
		if (r2==t) { s1++; last = 1; }
		i = ans+1;
	}
	if (s0 == s1)
		return -1;
	if (s0<s1 && last==0)
		return -1;
	if (s1<s0 && last==1)
		return -1;
	return max(s0,s1);
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		sum[i+1] = sum[i] + (a[i]==1);
	}
	vector < pair<int,int> > res;
	for (int t=1; t<=n; t++){
		int s = go(t);
		if (s != -1)
			res.push_back(pair<int,int>(s,t));
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (int i=0; i<(int)res.size(); i++)
		cout << res[i].first << ' ' << res[i].second << endl;
	return 0;
}