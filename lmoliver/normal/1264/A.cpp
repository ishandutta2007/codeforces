#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=400400;
int p[N];
int g,s,b;
void work(){
	int n;
	cin>>n;
	g=s=b=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int c=0;
	g=1;
	c++;
	while(c<n&&p[c+1]==p[c]){
		g++;
		c++;
	}
	while(c<n&&(!(s>g)||p[c+1]==p[c])){
		s++;
		c++;
	}
	int a1=0,a2=0,a3=0;
	while(c<n){
		b++;
		c++;
		if(c<=n/2&&b>g&&p[c+1]!=p[c]){
			a1=g;
			a2=s;
			a3=b;
		}
	}
	g=a1;
	s=a2;
	b=a3;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		work();
		printf("%d %d %d\n",g,s,b);
	}
	return 0;
}