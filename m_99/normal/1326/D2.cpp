#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000

template <typename T>
struct manacher{
	vector<int> A;
	manacher(T &s){
		A.resize(s.size(),-1);
		int i=0,j=0;
		while(i<s.size()) {
			while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j])j++;
			A[i] = j;
			int k = 1;
			while(i-k>=0&&i+k<s.size()&&k+A[i-k]<j){
				A[i+k] = A[i-k];
				k++;
			}
			i+=k;
			j-=k;
		}
	}

	
	//pos((+1)/2)
	int get_length(int pos){
		return A[pos];
	}
	
};

int main() {

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		string s;
		cin>>s;
		
		deque<char> D(s.size());
		for(int i=0;i<s.size();i++)D[i] = s[i];
		
		deque<char> s1(0),s2(0);
		
		while(true){
			if(D.size()<=1)break;
			if(D.front()==D.back()){
				s1.push_back(D.front());
				s2.push_front(D.front());
				D.pop_front();
				D.pop_back();
			}
			else{
				break;
			}
		}
		
		string amari = "";
		for(int i=0;i<D.size();i++){
			amari+='_';
			amari+=D[i];
		}
		amari+='_';
		manacher<string> m(amari);
		int maxi = 0;
		for(int i=0;i<amari.size();i++){
			int sz = m.get_length(i);
			if(i-sz==-1){
				maxi = max(maxi,sz);
			}
			if(i+sz==amari.size()){
				maxi = max(maxi,sz);
			}
		}
		string s3;
		for(int i=0;i<amari.size();i++){
			int sz = m.get_length(i);
			if(sz!=maxi)continue;
			if(i-sz==-1){
				s3 = amari.substr(0,maxi*2-1);
				break;
			}
			if(i+sz==amari.size()){
				s3 = amari.substr(i-maxi+1);
				break;
			}
		}
		string s4 = "";
		for(int i=0;i<s3.size();i++){
			if(s3[i]!='_')s4 += s3[i];
		}
		
		for(int i=0;i<s1.size();i++)printf("%c",s1[i]);
		
		cout<<s4;
		for(int i=0;i<s2.size();i++)printf("%c",s2[i]);
		printf("\n");
	}
		
	
    return 0;
}