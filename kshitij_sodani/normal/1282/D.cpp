
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n=-1;
int cot=0;
int ask(string s){
	cot++;
	if(cot>n+2 and n!=-1){
		while(true){
			continue;
		}
	}
	if(s.size()==0){
		while(true){
			continue;
		}
	}
	cout<<s<<endl;
	int x;
	cin>>x;
	return x;
}
int co[301];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	n=ask("a")+1;
	if(n==1){
		return 0;
	}
	if(n==301){
		string tt="";
		for(int i=0;i<300;i++){
		//	cout<<"b";
			tt+="b";
		}
		ask(tt);
	//	cout<<endl;
		return 0;
	}
	string s="";
	for(int i=0;i<n;i++){
		s+="a";
	}
	int x=ask(s);
	if(x==0){
		return 0;
	}
	if(x==n and n>1){
		string tt="";
		for(int i=0;i<n-1;i++){
		//	cout<<"b";
			tt+="b";
		}
		ask(tt);
	//	cout<<endl;
		return 0;
	}
	x=n-x;
	int le=n-x;
	for(int i=0;i<=x;i++){
		while(le>0){
			co[i]++;
			string ss="";
			for(int j=0;j<=x;j++){
				for(int k=0;k<co[j];k++){
					ss+="b";
				}
				if(j<x){
					ss+="a";
				}
			}
			int xx=ask(ss);
			if(xx!=(le-1)){
				co[i]--;
				break;;
			}
			if(xx==0){
				return 0;
			}
			le--;
		}
	}








	return 0;
}