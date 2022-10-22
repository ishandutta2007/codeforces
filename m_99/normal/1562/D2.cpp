#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,q;
		scanf("%d %d",&n,&q);
		string s;
		cin>>s;
		
		
		vector<int> S(n+1,0);
		rep(i,n){
			int t = 1;
			if(i%2==0)t *= -1;
			if(s[i]=='-')t *= -1;
			S[i+1] = t + S[i];
		}
		
		rep(__,q){
			int l,r;
			scanf("%d %d",&l,&r);
			l--;
			if(S[r]-S[l]==0){
				printf("0\n");
				continue;
			}
			vector<int> ans;
			if((r-l)%2==0){
				printf("2\n");
				ans.push_back(r);
				r--;
			}
			else{
				printf("1\n");
			}
			r--;
			long long t = S[r]-S[l];
			//cout<<t<<endl;
			if(t==0){
				ans.push_back(r+1);
			}
			else{
			//	cout<<t<<endl;
				int ok = r,ng = l-1;
				bool F = false;
				while(ok-ng>1){
					int mid = (ok+ng)/2;
					long long cur = S[mid] - S[l];
					cur -= S[r+1] - S[mid+1];
					/*
					if(cur == 0){
						ans.push_back(mid+1);
						F = true;
						break;
					}*/
					if(t>0){
						if(cur>=0)ok = mid;
						else ng=  mid;
					}
					else{
						if(cur<=0)ok = mid;
						else ng=  mid;
					}
				}
				/*
				while(true){
					if(S[ok]-S[l] - (S[r+1]-S[ok])!=0)ok--;
					else{
						ans.push_back(ok+1);
						break;
					}
				}*/
				//cout<<S[ok]-S[l] - (S[r+1]-S[ok+1])<<endl;
				//cout<<"hoge"<<endl;
				ans.push_back(ok+1);
			}
			rep(i,ans.size()){
				if(i!=0)printf(" ");
				printf("%d",ans[i]);
			}
			printf("\n");
		}
			
	}
	
	return 0;
}