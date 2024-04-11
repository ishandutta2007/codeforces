#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int p[1<<20];
int n;
int s[1<<20];

stack<int> st;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",p+i);
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		s[x-1]=-1;
	}
	for(int i=n-1;i>=0;--i){
		if(s[i]<0){
			st.push(p[i]);
		}
		else if(!st.empty()){
			if(p[i]==st.top()){
				s[i]=1;
				st.pop();
			}
			else {
				s[i]=-1;
				st.push(p[i]);
			}
		}
	}
	if(!st.empty()){puts("NO");return 0;}
	fore(i,0,n){
		if(s[i])continue;
		if(st.empty()||p[i]!=st.top())s[i]=1,st.push(p[i]);
		else s[i]=-1,st.pop();
	}
	if(!st.empty()){puts("NO");return 0;}
	puts("YES");
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",s[i]*p[i]);
	}
	puts("");
	return 0;
}