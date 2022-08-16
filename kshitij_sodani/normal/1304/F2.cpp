
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <functional>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <numeric>
#include <random>
#include <ratio>
#include <sstream>
#include <utility>

#include <bitset>
#include <deque>
#include <queue>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>
#include <set>

using namespace std;
#define a first
#define b second
#define pb push_back
typedef long long llo;
int tree[80001];
int lazy[80001];
int dp[51][20001];
int it[51][20001];
void build(int no,int l,int r,int ind){
	if(l==r){
		tree[no]=dp[ind][l];
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid,ind);
		build(no*2+2,mid+1,r,ind);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
void update(int no,int l,int r,int aa,int bb,int val){
	

	if(lazy[no]!=0){
		tree[no]+=lazy[no];
		if(r>l){
			lazy[no*2+1]+=lazy[no];
			lazy[no*2+2]+=lazy[no];
		}
		lazy[no]=0;
	}
	if(r<aa or l>bb){
		return;
	}
	if(l>=aa and r<=bb){
	//	cout<<l<<":"<<r<<endl;
		tree[no]+=val;
		if(r>l){
			lazy[no*2+1]+=val;
			lazy[no*2+2]+=val;
		}
	}
	else{
		int mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,val);
		update(no*2+2,mid+1,r,aa,bb,val);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>it[i][j];
		}
	}
	for(int i=0;i<m;i++){
		it[n][i]=0;
	}
	memset(dp,0,sizeof(dp));
/*	int tot2=0;
	for(int i=0;i<n;i++){
		tot2+=it[0][i];
		if(i>=k){
			tot2-=it[0][i-k];
		}
		dp[0][i]=tot2;
	}*/
	build(0,0,m-1,0);
	memset(lazy,0,sizeof(lazy));

//	cout<<tree[0]<<endl;
	for(int i=1;i<n+1;i++){
		
		if(i>1){
			update(0,0,m-1,0,k-1,-it[i-1][0]);
	//		cout<<0<<" "<<k-1<<" "<<-it[i-1][0]<<endl;
		}
		int tot=it[i][0]+it[i-1][0];
		dp[i][0]=tree[0]+tot;
	/*	for(int i=0;i<12;i++){
				cout<<tree[i]<<" ";
			}
			cout<<endl;*/
		for(int j=1;j<m;j++){
			tot+=it[i][j];
			tot+=it[i-1][j];
			if(j>=k){
				tot-=it[i][j-k];
				tot-=it[i-1][j-k];
			}

			if(i>1){
				if(j>=k){
					update(0,0,m-1,j-k,j-1,it[i-1][j-k]);
				//	cout<<11<<endl;

				}
				if(true){
					update(0,0,m-1,j,min(j+k-1,m-1),-it[i-1][j]);
			//		cout<<j<<" "<<min(j+k-1,m-1)<<" "<<-it[i-1][j]<<endl;
				}
			}
			//cout<<tree[0]<<" "<<tot<<endl;

			dp[i][j]=tree[0]+tot;
		/*	for(int i=0;i<12;i++){
				cout<<tree[i]<<" ";
			}
			cout<<endl;*/
		}

		build(0,0,m-1,i);
		memset(lazy,0,sizeof(lazy));
			/*for(int i=0;i<12;i++){
				cout<<tree[i]<<" ";
			}
			cout<<endl;*/
	}
	/*for(int i=0;i<n+1;i++){
		for(int j=0;j<m;j++){
			cout<<dp[i][j]<<",";
		}
		cout<<endl;
	}*/
	cout<<tree[0]<<endl;


	return 0;
}