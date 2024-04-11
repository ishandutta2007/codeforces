#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
typedef   long long int llo;
#define pb push_back
llo inf=100000000000;
#define mp make_pair
//llo tree[2000010];
llo it[500001];

/*
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=it[l];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
	}
}
llo query(llo no,llo l,llo r,llo a,llo b){
	if(l>b or r<a or l>r){
		return inf;
	}
	if(l>=a and r<=b){
		return tree[no];
	}
	else{
		llo mid=(l+r)/2;
		return min(query(no*2+1,l,mid,a,b),query(no*2+2,mid+1,r,a,b));
	}
}
*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	
	//build(0,0,n-1);
	
	vector<pair<int,int>> stack;
	
	int ll[n];
	stack.pb(mp(it[0],0));
	for(int i=1;i<n;i++){
		while(stack.size()>0){
			if(stack[stack.size()-1].first<=it[i]){
				ll[i]=stack[stack.size()-1].second;
				break;
			}
			else{
				stack.pop_back();
			}
		}
		stack.pb(mp(it[i],i));
	}
	int rr[n];
	stack.clear();
	stack.pb(mp(it[n-1],n-1));
	for(int i=n-2;i>=0;i--){
		while(stack.size()>0){
			if(stack[stack.size()-1].first<=it[i]){
				rr[i]=stack[stack.size()-1].second;
				break;
			}
			else{
				stack.pop_back();
			}
		}
		stack.pb(mp(it[i],i));
	}
	llo l[n];
	llo r[n];
	l[0]=it[0];
	llo maa=it[0];
	for(llo i=1;i<n;i++){
		if(maa>it[i]){
			l[i]=(i+1)*it[i];
		}
		else{
			/*llo low=0;
			llo high=i-1;
			while(low<high-1){
				llo mid=(low+high)/2;
				if(query(0,0,n-1,mid,i-1)>it[i]){
					high=mid-1;
					////cout<<"sad"<<endl;
				}
				else{
					low=mid;
				}
			}
			llo ind=low;
			for(llo j=high;j>low-1;j--){
		//		//cout<<j<<" "<<i-1<<end;
				if(query(0,0,n-1,j,i-1)<=it[i]){
					ind=j;

					break;
				}
			}*/
			llo ind=ll[i];
			//cout<<i<<" "<<ind<<endl;
			l[i]=l[ind]+(i-ind)*it[i];
		}
		maa=min(maa,it[i]);
	}

	r[n-1]=it[n-1];
	maa=it[n-1];
	for(llo i=n-2;i>=0;i--){
		if(maa>it[i]){
			r[i]=(n-i)*(it[i]);
		}
		else{
			/*llo low=i+1;
			llo high=n-1;*/
			/*while(low<high-1){
				llo mid=(low+high)/2;
				if(query(0,0,n-1,i+1,mid)>it[i]){
					low=mid+1;
				}
				else{
					high=mid;
				}
			}*/
			llo ind=rr[i];
			/*for(llo j=low;j<high+1;j++){
				if(query(0,0,n-1,i+1,j)<=it[i]){
					ind=j;
					break;
				}
			}*/
			r[i]=r[ind]+(ind-i)*it[i];
		}
		maa=min(maa,it[i]);
	}
	/*for(llo i=0;i<n;i++){
		//cout<<l[i]<<" ";
	}
	//cout<<endl;
	for(llo i=0;i<n;i++){
		//cout<<r[i]<<" ";
	}
	//cout<<endl;*/
	llo ans=0;
	llo ans2=0;
	for(llo i=0;i<n;i++){
		if(l[i]+r[i]-it[i]>ans){
			ans=l[i]+r[i]-it[i];
			ans2=i;
		}
	}
	llo arr[n];
	arr[ans2]=it[ans2];
	for(llo i=ans2-1;i>=0;i--){
		arr[i]=min(it[i],arr[i+1]);
	}
	for(llo i=ans2+1;i<n;i++){
		arr[i]=min(it[i],arr[i-1]);
	}
	for(llo i=0;i<n;i++){
		cout<<arr[i]<<" ";

	}
	cout<<endl;

	return 0;
}