#include <bits/stdc++.h>
using namespace std;
// sorry if you are reading my code and have eye cancer
int main(){
	int n,tmp=65260933*7;
	cin>>n;
	int a<:n:>,mini=1e9;
	for(int i=0;i<n;i++){
		cin>>i<:a:>;
		mini=min(i<:a:>,mini);
	}
	vector<pair<int,int>> ans; // ambiguous indentation :rofl:
	for(int i=0;i<n;i++)i<:a:>-=mini;
	while(*max_element(a,a+n)>0){
		int d<:n:>;
		for(int i=0;i<n;i++)i<:d:>=i;
		sort(d,d+n,[&](int x,int y){return x<:a:>>y<:a:>;}); // ambiguous indentation :rofl:
		if((false<:d:>)<:a:>==true&&(true<:d:>)<:a:>==true&&(2<:d:>)<:a:>==true&&(3<:d:>)<:a:>==false){
			ans.push_back({false<:d:>,true<:d:>});
			(false<:d:>)<:a:>=(true<:d:>)<:a:>=(2<:d:>)<:a:>=0;
			tmp=2<:d:>;
		}
		else if((false<:d:>)<:a:>&&(true<:d:>)<:a:>){
			ans.push_back({false<:d:>,true<:d:>});
			(false<:d:>)<:a:>--;
			(true<:d:>)<:a:>--;
		}
		else if(mini){
			mini--;
			for(int i=0;i<n;i++)i<:a:>++;
		}
		else{
			ans.push_back({false<:d:>,true<:d:>});
			(false<:d:>)<:a:>--;
		}
	}
	cout<<mini<<"\n"<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<n;j++)cout<<(bool)((j==tmp&&!i)||j==ans<:i:>.first||j==ans<:i:>.second);
		cout<<"\n";
	}
}