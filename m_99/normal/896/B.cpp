#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000001
bool check(vector<int> &now){
	for(int i=0;i<now.size();i++){
		if(now[i]<0)return false;
		if(i!=0&&now[i]<now[i-1])return false;
	}
	return true;
}

int main(){
	
	int n,m,c;
	cin>>n>>m>>c;
	
	vector<int> now(n,-1);
	
	for(int i=0;i<m;i++){
		if(check(now))break;
		int x;
		cin>>x;
		
		if(x<=c/2){
			for(int j=0;j<n;j++){
				if(now[j]==-1&&(j==0||now[j-1]<=x)){
					now[j] = x;
					cout<<j+1<<endl;
					break;
				}
				else if(j!=0&&now[j-1]>x){
					now[j-1]=x;
					cout<<j<<endl;
					break;
				}
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				if(now[j]==-1&&(j==n-1||now[j+1]>=x)){
					now[j] = x;
					cout<<j+1<<endl;
					break;
				}
				else if(j!=n-1&&now[j+1]<x){
					now[j+1]=x;
					cout<<j+2<<endl;
					break;
				}
			}
		}
	}
	
	return 0;
}