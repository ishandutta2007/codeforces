#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int it[200001];
int n,k;
int check2(int no){
	int co=1;

	vector<int> cur;
	int st=1;
	for(int i=1;i<n;i++){
		if(it[i]<=no){
			cur.pb(i);
			st=0;
		}
		else{
			if(st==0){
				if(cur.size()%2==0){
					co+=cur.size();
					cur.clear();
					st=1;
					continue;
				}
				co+=cur.size();
				cur.clear();
				co+=1;
				st=1;
			}
		}
	}

	co+=cur.size();

	return co>=k;
}
int check(int no){
	int co=0;

	vector<int> cur;
	int st=0;
	for(int i=0;i<n;i++){
		if(it[i]<=no){
			cur.pb(i);
			st=0;
		}
		else{
			if(st==0){
				if(cur.size()%2==0){
					co+=cur.size();
					cur.clear();
					st=1;
					continue;
				}
				co+=cur.size();
				cur.clear();
				co+=1;
				st=1;
			}
		}
	}
	/*if(no==2){
		cout<<co<<endl;
	}*/
	co+=cur.size();
	if(check2(no)){
		return 1;
	}
	return co>=k;

/*	while(i<=n){
		if(it[i]<=no){
			if(prev==1){
				co+=1;
				if(i<n-1){
					co+=1;
				}
				prev=1;
			}
		}
		else{
			if(prev!=1){

			}
		}
	}*/
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	int low=1;
	int high=1e9;
	while(low<high-1){
		int mid=(low+high)/2;
		if(check(mid)){
			high=mid;
		}
		else{
			low=mid;
		}
	}
	int ans=high;
	if(check(low)){
		ans=min(ans,low);
	}
	cout<<ans<<endl;



	return 0;
}