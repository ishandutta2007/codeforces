#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo it[100001];
const llo bb=500;
int ma;
const llo cc=210;
/*
const llo bb=1;
llo ma;
const llo cc=100000;*/
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
map<llo,int> tt;
llo n;
int pre[120000000];
llo ma5[100001];
const int xx=51000000;
void solve(){
	for(llo i=0;i<=bb;i++){
		for(llo j=0;j<n;j++){
			pre[it[j]-j*i+xx]++;
			ma=max(ma,pre[it[j]-j*i+xx]);
		}
		for(llo j=0;j<n;j++){
			pre[it[j]-j*i+xx]=0;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;

	for(llo i=0;i<n;i++){
		cin>>it[i];
	//	it[i]=i+1;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	ma=2;
	solve();
	//unordered_map<llo,llo,custom_hash> ss2;
	for(llo i=0;i<n;i+=cc){
		llo j=min(n-1,i+2*cc-1);
		for(llo k=i;k<=j;k++){
			for(llo l=k+1;l<=j;l++){
				if((abs(it[l]-it[k]))%(l-k)==0){
					llo x=(it[l]-it[k])/(l-k);
					pre[x+100000]++;
					ma5[l]=x+100000;
					ma=max(ma,pre[x+100000]+1);
				}
				else{
					ma5[l]=-1;
				}
			}
			for(llo l=k+1;l<=j;l++){
				if(ma5[l]>=0){
					pre[ma5[l]]--;
				}
			}
		}
	}

	for(llo i=0;i<n;i++){
		it[i]=100001-it[i];
	}
	solve();
	cout<<n-ma<<endl;




	return 0;
}