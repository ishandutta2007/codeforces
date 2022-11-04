#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+9,M=5e6+9,p=998244353;

int n,a[N];
long long ans;

struct HashTable {
	vector<int>hsh[M],num[M];
	int query(int x) {
		int y=(x^p)%(M-9);
		for(int i=0;i<hsh[y].size();i++)
			if(hsh[y][i]==x) return num[y][i];
		return 0;
	}
	void insert(int x) {
		int y=(x^p)%(M-9);
		if(query(x)) {
			for(int i=0;i<hsh[y].size();i++)
				if(hsh[y][i]==x) {num[y][i]++;break;}
		}
		else hsh[y].push_back(x), num[y].push_back(1);
	}
}ht;

int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) {
		for(int h=30;h>=1;h--) {
			int msk=(1<<h);
			if(a[i]<msk) ans+=ht.query(msk-a[i]);
			else break;
		}
		ht.insert(a[i]);
	}
	printf("%lld",ans);
	return 0;
}