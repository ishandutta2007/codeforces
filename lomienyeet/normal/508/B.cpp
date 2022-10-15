#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	bool done=false;
	int cur=-1;
	for(int i=0;i<s.length();i++){
		if(stoi(s.substr(i,1))%2==0){
			cur=i;
			if(stoi(s.substr(i,1))<stoi(s.substr(s.length()-1,1))){
				done=true;
				swap(s[i],s[s.length()-1]);
				break;
			}
		}
	}
	if(cur!=-1&&!done){
		done=true;
		swap(s[cur],s[s.length()-1]);
	}
	if(done)cout<<s<<"\n";
	else cout<<"-1\n";
	return 0;
}