#include<cstdlib>
#include<iostream>
using namespace std;
string s;
inline int sf(char ch){
	int sfch=s.find(ch);
	return sfch<0?(cout<<"NO",exit(0),string::npos):sfch;
}
inline int sf(char ch,int st){
	int sfch=s.find(ch,st);
	return sfch<0?(cout<<"NO",exit(0),string::npos):sfch;
}
main(){
    cin>>s;
    cout<<(sf('o',sf('l',sf('l',sf('e',sf('h')))+1))==string::npos?"NO":"YES");
}