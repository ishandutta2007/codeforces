#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int n;
char s[MAXN];
stack<int> a,b;
ll ans;
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++) {
		if(s[i]=='(') a.push(i);
		else b.push(i);
	}
	if(a.size()!=b.size()) return puts("-1"),0;
	int c1=0,c2=0;
	for(int i=0,pos=-1;i<n;i++) {
		if(s[i]=='(') {
			c1++;
			if(c1==c2) {
				ans+=i-pos;
				pos=i;
			}
		} else {
			c2++;
			if(c1==c2) 
				pos=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}