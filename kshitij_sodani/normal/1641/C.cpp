#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int n,q;
int tree[4*200001];
void update(int no,int l,int r,int i,int j){
	if(l==r){
		tree[no]=min(tree[no],j);
	}
	if(l<r){
		int mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j);
		}
		else{
			update(no*2+2,mid+1,r,i,j);
		}
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
	}
}
int query(int no,int l,int r,int aa,int bb,pair<int,int> cc){
	if(r<aa or l>bb or aa>bb){
		return 1e6;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	int mid=(l+r)/2;
	return min(query(no*2+1,l,mid,aa,bb,cc),query(no*2+2,mid+1,r,aa,bb,cc));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	set<int> ss;
	for(int i=0;i<n;i++){
		ss.insert(i);
	}
	for(int i=0;i<4*n;i++){
		tree[i]=n+1;
	}
	while(q--){
		int tt;
		cin>>tt;
		if(tt==0){
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			if(x==0){
				auto j=ss.lower_bound(l);
				vector<int> kk;
				while(j!=ss.end()){
					if((*j)<=r){
						kk.pb(*j);
						j++;
					}
					else{
						break;
					}
				}
				for(auto j:kk){
					ss.erase(j);
				}
			}
			else{
				update(0,0,n-1,l,r);
			}
		}
		else{
			int x;
			cin>>x;
			x--;
			if(ss.find(x)==ss.end()){
				cout<<"NO"<<endl;
				continue;
			}
			auto j=ss.upper_bound(x);
			int r=n-1;
			if(j!=ss.end()){
				r=((*j))-1;
			}
			int l=0;
			j=ss.lower_bound(x);
			if(j!=ss.begin()){
				j--;
				l=(*j)+1;
			}
			int su=query(0,0,n-1,l,x,{x,r});
			if(su<=r){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"N/A"<<endl;
			}
			//check if in range (l,x) there is element in range [x,r]

		}
	}



 
 
 
	return 0;
}