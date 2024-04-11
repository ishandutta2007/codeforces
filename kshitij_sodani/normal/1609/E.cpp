//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[100001];
int n,q;
int co[10];
int tree[4*100001][3][3];//min subarray sum

void build(int no,int l,int r){
	if(l==r){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i<=j){
					if(i==j and i==it[l]){
						tree[no][i][j]=1;
					}
					else if(i==j){
						tree[no][i][j]=0;
					}
					else{
						tree[no][i][j]=0;
					}
				}
			}
		}
		/*tree2[no]=tt[l];
		tree[no]=0;
		tree[no]=min(tree[no],tree2[no]);
		le[no]=tree[no];
		re[no]=tree[no];*/
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				tree[no][i][j]=n;
			}
		}

		for(int i=0;i<3;i++){
			for(int j=i;j<3;j++){
				for(int k=j;k<3;k++){

					tree[no][i][k]=min(tree[no][i][k],tree[no*2+1][i][j]+tree[no*2+2][j][k]);
				}
			}
		}
		/*tree2[no]=tree2[no*2+1]+tree2[no*2+2];
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
		tree[no]=min(tree[no],re[no*2+1]+le[no*2+2]);
		//tree[no]=min(tree[no],tree2[no*2+1]+le[no*2+2]);
		//tree[no]=min(tree[no],tree2[no*2+2]+re[no*2+1]);
		le[no]=min(le[no*2+1],tree2[no*2+1]+le[no*2+2]);
		re[no]=min(re[no*2+2],tree2[no*2+2]+re[no*2+1]);*/

	}
	//cout<<l<<":"<<r<<":"<<tree[no]<<endl;
}
void update(int no,int l,int r,int i,int j){
	if(l==r){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i<=j){
					if(i==j and i==it[l]){
						tree[no][i][j]=1;
					}
					else if(i==j){
						tree[no][i][j]=0;
					}
					else{
						tree[no][i][j]=0;
					}
				}
			}
		}
		/*tree2[no]=tt[l];
		tree[no]=0;
		tree[no]=min(tree[no],tree2[no]);
		le[no]=tree[no];
		re[no]=tree[no];*/
	}
	else{
		int mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j);
		}
		else{
			update(no*2+2,mid+1,r,i,j);
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				tree[no][i][j]=n;
			}
		}
		for(int i=0;i<3;i++){
			for(int j=i;j<3;j++){
				for(int k=j;k<3;k++){
					tree[no][i][k]=min(tree[no][i][k],tree[no*2+1][i][j]+tree[no*2+2][j][k]);
				}
			}
		}
		
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		it[i]=s[i]-'a';
		co[it[i]]++;
		
	}
	build(0,0,n-1);
	
	//cout<<tree3[0]<<":"<<endl;
	//cout<<tree[0][0][2]<<endl;
	//cout<<n-co[1]+tree[0]<<endl;
	while(q--){
		int ind;
		cin>>ind;
		ind--;
		co[it[ind]]--;
		char s;
		cin>>s;


		int j=s-'a';

		it[ind]=j;
		update(0,0,n-1,ind,j);
		cout<<tree[0][0][2]<<endl;
	

	}




 
	return 0;
}