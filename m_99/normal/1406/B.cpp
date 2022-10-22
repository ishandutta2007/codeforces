#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo N
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		int N,K;
		cin>>N;
		K = 5;
		vector<long long> P,M,Z;
	
		vector<long long> A(N);
		for(int i=0;i<N;i++){
			cin>>A[i];
			if(A[i]==0)Z.push_back(0);
			else if(A[i]>0)P.push_back(A[i]);
			else M.push_back(A[i]);
		}
		if(P.size()+M.size()<K){
			cout<<0<<endl;
			continue;
		}
		
		if((P.size()+M.size()==K && M.size()%2==1)||(P.size()==0&&K%2==1)){
			if(Z.size()>0){
				cout<<0<<endl;
			}
			else{
				sort(P.rbegin(),P.rend());
				sort(M.begin(),M.end());
				long long ans = 1;
				for(int i=0;i<K;i++){
					if(P.size()==0){
						A1:
						ans *= M.back();
						M.pop_back();
					}
					else if(M.size()==0){
						A0:
						ans *= P.back();
						P.pop_back();
					}
					else if(P.back()<abs(M.back())){
						goto A0;
					}
					else goto A1;
				}
				cout<<ans<<endl;
			}
			continue;
		}
		
		sort(P.begin(),P.end());
		sort(M.rbegin(),M.rend());
	 
		vector<long long> X;
		int c = 0;
		for(int i=0;i<K;i++){
			if(P.size()==0){
				C1:
				X.push_back(M.back());
				c++;
				M.pop_back();
			}
			else if(M.size()==0){
				C0:
				X.push_back(P.back());
				P.pop_back();
			}
			else if(P.back()>abs(M.back())){
				goto C0;
			}
			else goto C1;
		}
		
		if(c%2==1){
			if(M.size()==0){
				B0:
				for(int i=X.size()-1;i>=0;i--){
					if(X[i]<0){
						
						X.erase(X.begin()+i);
						break;
					}
				}
				X.push_back(P.back());
			}
			else if(P.size()==0){
				B1:
				for(int i=X.size()-1;i>=0;i--){
					if(X[i]>0){
						X.erase(X.begin()+i);
						break;
					}
				}
				X.push_back(M.back());
			}
			else{
				long long aa = P.back(),bb = M.back();
				for(int i=X.size()-1;i>=0;i--){
					if(X[i]>0){
						aa *= X[i];
						break;
					}
					if(i==0)goto B0;
				}
				for(int i=X.size()-1;i>=0;i--){
					if(X[i]<0){
						bb *= X[i];
						break;
					}
					if(i==0)goto B1;
				}
				if(aa>bb)goto B0;
				else goto B1;
			}
		}
		
		long long ans = 1;
		for(int i=0;i<X.size();i++)ans *= X[i];
		
		cout<<ans<<endl;
		
	}
	
    return 0;
}