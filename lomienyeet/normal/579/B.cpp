#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> str;
    vector<int> res(2*N);
    map<int,pair<int,int> >bruh;
    fill(res.begin(),res.end(),-1);
	for(int i=1,k=1;i<=2*N-1;i++,k++){
		for(int j=0;j<k;j++){
		    int temp;
		    cin>>temp;
			pair<int,int> p=make_pair(i,j);
			bruh[temp]=p;
			str.push_back(temp);
		}
	}
	sort(str.begin(),str.end());
	for(int i=str.size()-1;i>=0;i--){
		pair<int,int> tmp=bruh[str[i]];
		if(res[tmp.first]==-1 && res[tmp.second]==-1){
			res[tmp.first]=tmp.second+1;
			res[tmp.second]=tmp.first+1;
		}
	}
	for(int i=0;i<res.size();i++){
		cout<<res[i];
		if(i+1!=res.size())cout << " ";
	}
	return 0;
}