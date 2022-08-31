#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int n,m,k;
int tree[800000][10][10];
int val[800000][2];

int lazy[800000];
int it[200000];

void build(int no,int l,int r){
	lazy[no]=-1;
	if(l==r){
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				tree[no][i][j]=0;
			}
		}
		val[no][0]=it[l];
		val[no][1]=it[l];
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				tree[no][i][j]=tree[no*2+1][i][j]+tree[no*2+2][i][j];
			}
		}
		tree[no][it[mid]][it[mid+1]]+=1;
		val[no][0]=val[no*2+1][0];
		val[no][1]=val[no*2+2][1];
	}
}
void update(int no,int l,int r,int aa,int bb,int ii){

	if(lazy[no]>-1){
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				tree[no][i][j]=0;
			}
		}
		tree[no][lazy[no]][lazy[no]]=(r-l);
		if(l<r){
			lazy[no*2+1]=lazy[no];
			lazy[no*2+2]=lazy[no];
		}
		val[no][0]=lazy[no];
		val[no][1]=lazy[no];
		lazy[no]=-1;
	}
	//cout<<l<<":"<<r<<endl;

	if(r<aa or l>bb){
		return;
	}
	if(aa<=l and r<=bb){
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				tree[no][i][j]=0;
			}
		}
		tree[no][ii][ii]=(r-l);
		val[no][0]=ii;
		val[no][1]=ii;
		if(l<r){
			lazy[no*2+1]=ii;
			lazy[no*2+2]=ii;
		}
	//	cout<<l<<","<<r<<","<<ii<<endl;
	//	cout<<l<<","<<r<<endl;
	}
	else{
		int mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,ii);
		update(no*2+2,mid+1,r,aa,bb,ii);
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				tree[no][i][j]=tree[no*2+1][i][j]+tree[no*2+2][i][j];
			}
		}
		val[no][0]=val[no*2+1][0];
		val[no][1]=val[no*2+2][1];
	//	cout<<l<<","<<r<<","<<val[no][0]<<','<<val[no][1]<<endl;
		tree[no][val[no*2+1][1]][val[no*2+2][0]]+=1;
	//	cout<<tree[no][2][0]<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m>>k;

	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		it[i]=s[i]-'a';
	}
	build(0,0,n-1);
	int aa;
	int bb,cc;
	char dd;
	/*for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			cout<<tree[0][i][j]<<",";
		}
		cout<<endl;
	}*/
	for(int i=0;i<m;i++){
		
		cin>>aa;
		if(aa==1){
			cin>>bb>>cc>>dd;
			update(0,0,n-1,bb-1,cc-1,dd-'a');
		/*	for(int i=0;i<k;i++){
				for(int j=0;j<k;j++){
					cout<<tree[0][i][j]<<",";
				}
				cout<<endl;
			}*/
		}
		else{
			string ss;
			cin>>ss;
			int ans=1;
			for(int i=0;i<k;i++){
				for(int j=0;j<i;j++){
					ans+=tree[0][ss[i]-'a'][ss[j]-'a'];
				}
				ans+=tree[0][i][i];
			}
			cout<<ans<<endl;
		}
	}

 
 
	return 0;
}