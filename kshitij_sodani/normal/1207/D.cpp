#include <iostream>
#include<bits/stdc++.h>
#include <algorithm> 
using namespace std;
typedef long long in;
bool fun(pair<in,in> a,pair<in,in> b){
    return a.second<b.second;
}
bool fun2(pair<in,in> a,pair<in,in> b){

    return a.first<b.first;
}
bool fun3(pair<in,in> a,pair<in,in> b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    return a.second<b.second;
}
pair<in,in> a[300001];
in pre[300001];
int main(){

	int n,i;
//	pair<int,int> a[n];
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%d%d",&a[i].first,&a[i].second);
	}

//	cout<<*a;
	
	
	in aa=1;
	in mod=998244353;
	for(i=1;i<n+1;i++){
	    aa*=i;
	    aa%=mod;
	    pre[i-1]=aa;
	}
	in ans=aa;
	
//	cout<<ans<<endl;
	in ind=0;
	in c=1;
	std::sort(a,a+n,fun2);
	
	while(ind<n){
	    in i=ind;
	    while(a[ind].first==a[i].first){
	        ind++;
	        if(ind==n){
	            break;
	        }
	    }
	    
	    c*=pre[ind-i-1];
	    c%=mod;
	    
	}
	
	ans-=c;
//	cout<<c<<endl;
	ind=0;
	c=1;

	sort(a,a+n,fun);
	while(ind<n){
	    int i=ind;
	    while(a[ind].second==a[i].second){
	        ind++;
	        if(ind==n){
	            break;
	        }
	    }
	    c*=pre[ind-i-1];
	    c%=mod;
	}
	ans-=c;
//	cout<<c<<endl;
	ind=0;
	c=1;
	in ab[n];
	for(int i=0;i<n;i++){
	    ab[i]=a[i].second;
//	    cout<<ab[i]<<" ";
	    
	}
//	cout<<endl<<endl;
	sort(a,a+n,fun3);
	in ac[n];
	int st=0;
	for(int i=0;i<n;i++){
	    ac[i]=a[i].second;
	//    cout<<ac[i]<<" ";
	    if(ac[i]!=ab[i]){
	        st=1;
	    }
	}
//	cout<<endl<<endl;
	if(st==1){
	    int p=0;
	  //  cout<<"bb"<<endl;
	}
	else{
    	while(ind<n){
    	    int i=ind;
    	    while(a[ind]==a[i]){
    	        ind++;
    	        if(ind==n){
    	            break;
    	        }
    	    }
    	    c*=pre[ind-i-1];
    	    c%=mod;
    	}
    //	cout<<c<<endl;
    	ans+=c;
	}
	while(ans<0){
	    ans+=mod;
	}
    while(ans>=mod){
        ans-=mod;
    }

	cout<<ans;
	
	
	
	return 0;
}