#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAXN 200005


struct statu{
	long long val;
	int tag;
	statu(){}
	statu(long long a,int b):val(a),tag(b){}
	bool operator < (statu a) const {
		return val>a.val;
	}
};
int n,k,x;
long long a[MAXN];

inline void work() {
	priority_queue<statu> q;
	for (int i=1;i<=n;i++) {
		q.push(statu(abs(a[i]),i));
	}
	while (k && !q.empty()) {
		statu now=q.top();q.pop();
		if (a[now.tag]<0) {
			a[now.tag]-=x;
		}
		else {
			a[now.tag]+=x;
		}
		q.push(statu(abs(a[now.tag]),now.tag));
		k--;
	}
	for (int i=1;i<=n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main() {
	cin>>n>>k>>x;
	int f=1,zcnt=0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]<0) f^=1;
		if (a[i]==0) {
			zcnt++;
		}
	}
	if (k<zcnt) {
		for (int i=1;i<=n;i++) {
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return 0;
	}
	if (f) {
		if (zcnt) {
			for (int i=1,flag=1;i<=n;i++) {
				if (a[i]==0) {
					if (flag) {
						flag=0;
						a[i]=-x;
					}
					else {
						a[i]=x;
					}
					k--;
				}
			}
		}
		else {
			long long minabs=1234567890123456ll;
			int tag=-1;
			for (int i=1;i<=n;i++) {
				if (abs(a[i])<minabs) {
					minabs=abs(a[i]);
					tag=i;
				}
			}
			if (minabs<(long long)k*x) {
				int times=(minabs/x)+1;
				k-=times;
				if (a[tag]<0) {
					a[tag]+=times*x;
				}
				else {
					a[tag]-=times*x;
				}
			}
			else {
				if (a[tag]<0) {
					a[tag]+=k*x;
				}
				else {
					a[tag]-=k*x;
				}
				for (int i=1;i<=n;i++) {
					cout<<a[i]<<" ";
				}
				cout<<endl;
				return 0;
			}
		}
	}
	work();
	return 0;
}