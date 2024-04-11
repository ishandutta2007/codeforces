#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,cnt=0;
	cin>>N;
	for(int i=0,u,v;i<N;i++){
		cin>>u>>v;
		if(v-u>=2)cnt++;
	}
	cout<<cnt;
}