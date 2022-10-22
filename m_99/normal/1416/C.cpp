#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300


vector<vector<long long>> C(2,vector<long long>(30,0));
void go(vector<int> a,int d){
	if(a.size()==0)return;
	long long cnt0 = 0LL,cnt1 = 0LL;
	vector<int> A,B;
	rep(i,a.size()){
		if((a[i]>>d)&1){
			cnt1++;
			C[1][d]+=cnt0;
			A.push_back(a[i]);
		}
		else{
			cnt0++;
			C[0][d]+=cnt1;
			B.push_back(a[i]);
		}
	}
	if(d!=0){
		go(A,d-1);
		go(B,d-1);
	}
}

int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	
	go(a,29);
	
	long long ans = 0LL;
	long long X = 0LL;
	
	for(int i=29;i>=0;i--){
		if(C[0][i]<=C[1][i]){
			ans += C[0][i];
		}
		else{
			ans += C[1][i];
			X |= (1<<i);
		}
	}
	
	cout<<ans<<' '<<X<<endl;
	
    return 0;
}