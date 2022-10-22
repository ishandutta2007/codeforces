#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
#include <utility>

using namespace std;
typedef long long int llint;
//#include <bits/stdc++.h>
#define pub push_back

int main(void){
	string S;cin>>S;
	int K=0,i,n=S.size();
	char mae='_';
	vector<int>in;
	in.pub(0);
	for(i=0;i<n;i++){
		if(mae!=S[i]){in.pub(0);}
		in.back()++;
		mae=S[i];
	}
	if(mae=='#'){in.pub(0);}
	//for(i=0;i<in.size();i++){cerr<<in[i]<<" ";}cerr<<endl;
	in[0]++;in.back()++;
	//K
	for(K=0;K<=5;K++){
		vector<int>ans={};
		int ok=1;
		//for(i=0;i<in.size();i++){cerr<<in[i]<<" ";}cerr<<endl;
		for(i=0;i<in.size();i++){
			
			if(i%2==0){
				int x=in[i];
				if(x<K+1){ok=0;}
				x-=K+1;
				if(K==0&&x>0){ok=0;}
				if(K==1&&x%2>0){ok=0;}
				if(x==1){ok=0;}
				while(x>3){ans.pub(1);x-=2;}
				if(x==3){ans.pub(2);}
				else if(x==2){ans.pub(1);}
			}else{
				ans.pub(in[i]+K);
			}
			if(ok==0){break;}
		}
		if(ok){
			//cerr<<"K="<<K<<endl;
			cout<<ans.size()<<endl;
			for(auto it:ans){cout<<it<<" ";}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}