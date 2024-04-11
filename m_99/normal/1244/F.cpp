#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int n,k;
	cin>>n>>k;
	
	string S;
	cin>>S;
	
	vector<bool> f(n,false);
	
	for(int i=0;i<n;i++){
		if(S[i]==S[(i+1)%n])continue;
		if(S[i]==S[(i-1+n)%n])continue;
		f[i]=true;
	}
	
	vector<pair<int,int>> P;
	int last = -1;
	for(int i=0;i<n;i++){
		if(f[i]){
			if(last==-1)last=i;
			if(i==n-1){
				P.emplace_back(last,i);
			}
		}
		else{
			if(last!=-1){
				P.emplace_back(last,i-1);
				last=-1;
			}
		}
	}
	
	if(P.size()>=2){
		if(P[0].first==0&&P.back().second==n-1){
			P[0].first = P.back().first;
			P.pop_back();
		}
	}
	
	vector<int> cnt(n,-1);
	
	for(int i=0;i<n;i++){
		if(f[i]==false){
			cnt[i]=0;
		}
	}
	
	for(int i=0;i<P.size();i++){
		int l = P[i].first;
		int r = P[i].second;
		for(int j=0;j<k;j++){
			if(cnt[l]!=-1||cnt[r]!=-1)break;
			cnt[l]=(j+1)%2;
			cnt[r] = (j+1)%2;
			l = (l+1)%n;
			r = (r+n-1)%n;
		}
		
		while(true){
			if(cnt[l]!=-1||cnt[r]!=-1)break;
			cnt[l]=k%2;
			cnt[r]=k%2;
			l = (l+1)%n;
			r = (r+n-1)%n;
		}
		
	}
	
	if(P.size()==1&&P[0].first==0&&P[0].second==n-1){
		for(int i=0;i<n;i++){
			if(k%2==1)cnt[i]=1;
			else cnt[i]=0;
		}
	}
	
	for(int i=0;i<n;i++){
		if(cnt[i]==1){
			if(S[i]=='B')S[i]='W';
			else S[i]='B';
		}
	}
	
	cout<<S<<endl;
			
	
    return 0;
}