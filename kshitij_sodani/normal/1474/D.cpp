//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[200001];
llo n;

llo pre[200001];
llo ma[200001];
llo ma2[200001];
/*llo tree[200001];
llo lazy[200001];
void push(llo no,llo l,llo r){
	tree[no]+=lazy[no];
	if(l<r){
		lazy[no*2+1]+=lazy[no];
		lazy[no*2+2]+=lazy[no];
	}
	lazy[no]=0;
}
llo pre[200001];
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=pre[i];
	}
	else{

	}
}
void update(llo no,llo l,llo r,llo aa,llo bb,llo cc){

	if(l>bb or r<aa){
		return;
	}
	push(no,l,r);

	if(aa<=l and r<=bb){
		tree[no]+=cc;
		if(l<r){
			lazy[no*2+1]+=cc;
			lazy[no*2+2]+=cc;
		}
	}
	else{
		llo mid=(l+r)
	}

}*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		cin>>n;
		llo su=0;
		llo ac=0;
		llo bc=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			su+=it[i];
			if(i%2==0){
				ac+=it[i];
			}
			else{
				bc+=it[i];
			}
		}
		if(su%2==1){
			cout<<"NO"<<endl;
			continue;
		}

		llo st=0;
		llo kk=1;
		for(llo i=0;i<n;i++){
			pre[i]=it[i];
			if(i>0){
				pre[i]-=pre[i-1];
			}
			if(pre[i]<0){
				kk=0;
			}
			ma[i]=pre[i];
			if(i>=2){
				ma[i]=min(ma[i],ma[i-2]);
			}
		}
		if(ac!=bc){
			kk=0;
		}
		st|=kk;
		for(llo i=n-1;i>=0;i--){
			ma2[i]=pre[i];
			if(i+2<n){
				ma2[i]=min(ma2[i],ma2[i+2]);
			}
		}

		for(llo i=0;i<n-1;i++){
			llo stt=1;
			if(i>0){
				if(ma[i-1]<0){
					stt=0;
				}
			}
			if(i>1){
				if(ma[i-2]<0){
					stt=0;
				}
			}
			if(i+2<n){
				if(ma2[i+2]-2*it[i]+2*it[i+1]<0){
					stt=0;
				}
			}
			if(i+1<n){
				if(ma2[i+1]+2*it[i]-2*it[i+1]<0){
					stt=0;
				}
			}
			if(pre[i]-it[i]+it[i+1]<0){
				stt=0;
			}
			if(i%2==0){
				ac-=it[i];
				bc+=it[i];
				ac+=it[i+1];
				bc-=it[i+1];
			}
			else{
				ac+=it[i];
				bc-=it[i];
				ac-=it[i+1];
				bc+=it[i+1];
			}
			if(ac!=bc){
				stt=0;
			}

			if(stt==1){
				st=1;
			}






			if(i%2==1){
				ac-=it[i];
				bc+=it[i];
				ac+=it[i+1];
				bc-=it[i+1];
			}
			else{
				ac+=it[i];
				bc-=it[i];
				ac-=it[i+1];
				bc+=it[i+1];
			}
		}
		






		if(st){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}


	}





	
 
	return 0;
}