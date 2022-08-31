#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
//#define endl '\n'
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	pair<int,int> aa[n];
	pair<int,int> bb[n];
	int ff[n];

	for(int i=0;i<n;i++){
		ff[i]=0;
		cin>>aa[i].a;
		aa[i].b=i;
	}
	for(int j=0;j<n;j++){
		cin>>bb[j].a;
		bb[j].b=j;
	}
	sort(aa,aa+n);
	sort(bb,bb+n);
	int ma=0;
	for(int i=0;i<n;i++){
		if(bb[i].b>=aa[i].b){
			ff[bb[i].b-aa[i].b]+=1;
		}
		else{
			ff[n-(aa[i].b-bb[i].b)]+=1;
		}
	}
	for(int i=0;i<n;i++){
		ma=max(ma,ff[i]);
	}
	cout<<ma<<endl;


	

	return 0;
}