#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		
		vector<int> p(n);
		for(int j=0;j<n;j++){
			scanf("%d",&p[j]);
		}
		vector<int> V;
		for(int j=0;j<n;j++){
			if(j==0){
				V.push_back(1);
			}
			else{
				if(p[j]==p[j-1]){
					V.back()++;
				}
				else{
					V.push_back(1);
				}
			}
		}
		vector<int> VV;
		int sum = 0;
		for(int j=0;j<n;j++){
			if(2*(sum+V[j])>n)break;
			sum+=V[j];
			VV.push_back(V[j]);
		}
		vector<long long> S(VV.size());
		for(int j=0;j<VV.size();j++){
			if(j==0)S[j]=(long long)VV[j];
			else{
				S[j] = S[j-1];
				S[j] += (long long)VV[j];
			}
		}
		int gg=0,ss=0,bb=0;
		for(int j=0;j<VV.size();j++){
			long long g = S[j];
			int ok = VV.size();
			int ng = j;
			while(ok-ng>1){
				int mid = (ok+ng)/2;
				long long s = S[mid] - S[j];
				if(s>g)ok=mid;
				else ng=mid;
			}
			if(ok==VV.size())continue;
			if(S.back() - S[ok] > g){
				gg=g;
				ss=S[ok]-S[j];
				bb=S.back()-S[ok];
				break;
			}
		}
		
		cout<<gg<<' '<<ss<<' '<<bb<<endl;
	}
	
	
	return 0;
}