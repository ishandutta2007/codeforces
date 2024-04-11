#include <bits/stdc++.h>
using namespace std;

int n,k,code;
int a[1<<20];
int lmax[1<<20],lsum[1<<20],rmax[1<<20],rsum[1<<20];
int cnt[1<<20],mark[1<<20];

long long go (int lo, int hi){
	if (lo == hi)
		return 0;
	int mid = (lo + hi) / 2;
	long long ans = go(lo, mid);
	ans+= go(mid+1, hi);
	lmax[mid] = a[mid];
	lsum[mid] = a[mid]%k;
	for (int i=mid-1; i>=lo; i--){
		lmax[i] = max(lmax[i+1],a[i]);
		lsum[i] = (lsum[i+1] + a[i])%k;
	}
	rmax[mid+1] = a[mid+1];
	rsum[mid+1] = a[mid+1]%k;
	for (int i=mid+2; i<=hi; i++){
		rmax[i] = max(rmax[i-1],a[i]);
		rsum[i] = (rsum[i-1]+a[i]) % k;
	}
	code++;
	int poi = mid;
	for (int i=mid+1; i<=hi; i++){
		while (poi>=lo && lmax[poi] <= rmax[i]){
			if (mark[lsum[poi]] != code)
				mark[lsum[poi]] = code, cnt[lsum[poi]] = 1;
			else
				cnt[lsum[poi]]++;
			poi--;
		}
		int who = (rmax[i]-rsum[i])%k; if (who<0) who+= k;
		if (mark[who] == code)
			ans+= cnt[who];
	}
	code++;
	poi = mid+1;
	for (int i=mid; i>=lo; i--){
		while (poi<=hi && rmax[poi] < lmax[i]){
			if (mark[rsum[poi]] != code)
				mark[rsum[poi]] = code, cnt[rsum[poi]] = 1;
			else
				cnt[rsum[poi]]++;
			poi++;
		}
		int who = (lmax[i]-lsum[i])%k; if (who<0) who+= k;
		if (mark[who] == code)
			ans+= cnt[who];
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	cout << go(0,n-1) << endl;
	return 0;
}