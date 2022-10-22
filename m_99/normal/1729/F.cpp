#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		
		string s;
		cin>>s;
		int n = s.size();
		int w,m;
		cin>>w>>m;
		
		vector<int> mod9(n,-1);
		{
			int sum = 0;
			rep(i,n){
				sum += s[i] - '0';
				sum %= 9;
				if(i-w>=0){
					sum += 9;
					sum -= s[i-w]-'0';
					sum %= 9;
				}
				if(i-w+1>=0){
					mod9[i-w+1] = sum;
				}
			}
		}
		/*
		rep(i,n){
			cout<<mod9[i]<<endl;
		}
		*/
		vector<vector<int>> ind(9);
		rep(i,n){
			if(mod9[i]==-1)continue;
			if(ind[mod9[i]].size()>=2)continue;
			ind[mod9[i]].push_back(i);
		}
		
		vector<int> sum(n+1,0);
		rep(i,n){
			sum[i+1] += s[i]-'0';
			sum[i+1] += sum[i];
		}
		
		rep(i,m){
			int l,r,kk;
			scanf("%d %d %d",&l,&r,&kk);
			l--,r--;
			int V = sum[r+1] - sum[l];
			V %= 9;
			pair<int,int> L12(Inf32,Inf32);
			rep(j,9){
				if(ind[j].size()==0)continue;
				rep(k,9){
					if(ind[k].size()==0)continue;
					if((j*V+k)%9==kk){
						if(j==k){
							if(ind[k].size()!=2)continue;
							L12 = min(L12,make_pair(ind[j][0],ind[j][1]));
						}
						else{
							L12 = min(L12,make_pair(ind[j][0],ind[k][0]));
						}
						
					}
				}
			}
			if(L12.first==Inf32)L12 = make_pair(-1,-1);
			else{
				L12.first++;
				L12.second++;
			}
			printf("%d %d\n",L12.first,L12.second);
		}
	}
	
	return 0;
}