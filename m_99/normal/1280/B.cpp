#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

int main(){
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int h,w;
		cin>>h>>w;
		vector<string> grid(h,string(w,' '));
		int cnt = 0;
		for(int j=0;j<h;j++){
			cin>>grid[j];
			for(int k=0;k<w;k++){
				if(grid[j][k] == 'A')cnt++;
			}
		}
		
		if(cnt==h*w){
			cout<<0<<endl;
			continue;
		}
		if(cnt==0){
			cout<<"MORTAL"<<endl;
			continue;
		}
		bool F = false;
		bool f = true;
		for(int j=0;j<h;j++){
			if(grid[j][0]=='P'){
				f=false;
			}
			else{
				F=true;
			}
		}
		if(f){
			cout<<1<<endl;
			continue;
		}
		
		f = true;
		for(int j=0;j<h;j++){
			if(grid[j][w-1]=='P'){
				f=false;
			}
			else{
				F=true;
			}
		}
		if(f){
			cout<<1<<endl;
			continue;
		}
		
		f = true;
		for(int j=0;j<w;j++){
			if(grid[0][j]=='P'){
				f=false;
			}
			else{
				F=true;
			}
		}
		if(f){
			cout<<1<<endl;
			continue;
		}
		f = true;
		for(int j=0;j<w;j++){
			if(grid[h-1][j]=='P'){
				f=false;
			}
			else{
				F=true;
			}
		}
		if(f){
			cout<<1<<endl;
			continue;
		}
		
		if(grid[0][0]=='A'||grid[0][w-1]=='A'||grid[h-1][0]=='A'||grid[h-1][w-1]=='A'){
			cout<<2<<endl;
			continue;
		}
		
		for(int j=0;j<h;j++){
			bool X = true;
			for(int k=0;k<w;k++){
				if(grid[j][k] == 'P'){
					X = false;
					break;
				}
			}
			if(X){
				f=true;
				break;
			}
		}
		
		for(int j = 0;j<w;j++){
			bool X = true;
			for(int k=0;k<h;k++){
				if(grid[k][j]=='P'){
					X=false;
					break;
				}
			}
			if(X){
				f=true;
				break;
			}
		}
		
		if(f){
			cout<<2<<endl;
			continue;
		}
		
		if(F){
			cout<<3<<endl;
		}
		else{
			cout<<4<<endl;
		}
		
		
	}
	
	return 0;
}