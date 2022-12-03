#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,t,x,y,n,m,len;
char s[500500];
 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	len=1;
	for(i=1;i<n;i++){
		if(s[j]<s[i]){break;}
		if(s[j]>s[i]){len=i+1;j=0;continue;}
		j=(j+1)%len;
	}
	for(i=0;i<m;i++){
		cout<<s[i%len];
	}
}