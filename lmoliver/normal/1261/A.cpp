#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5050;
char b[N];
int find(char c,int s){
	for(int i=s;;i++){
		if(b[i]==c){
			return i;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cin>>b;
		printf("%d\n",n);
		int w=2*(k-1);
		for(int i=0;i<n;i++){
			char c=i<w?i%2==0?'(':')':i<w+(n-w)/2?'(':')';
			// cerr<<c<<endl;
			int x=find(c,i);
			printf("%d %d\n",i+1,x+1);
			reverse(b+i,b+x+1);
		}
	}
	return 0;
}