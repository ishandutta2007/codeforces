#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	map<int,int> z;
	set<int> pos;
	set<int> neg;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		z[a[i]] = i;
	}
	for(int i = 0; i < n; i++){
		if(i > 0){
			int c = -1;
			int d = -1;
			if(pos.lower_bound(a[i]) != pos.end()){
				c = z[*pos.lower_bound(a[i])];
			}
			if(neg.lower_bound(-a[i]) != neg.end()){
				d = z[-*neg.lower_bound(-a[i])];
			}
			printf("%d\n", a[max(c,d)]);
		}
		pos.insert(a[i]);
		neg.insert(-a[i]);
	}
}