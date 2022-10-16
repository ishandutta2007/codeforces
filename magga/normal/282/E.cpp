#include<bits/stdc++.h>
using namespace std;
typedef struct data{
	data* bit[2];
	int cnt = 0;
}trie;
trie* head;
int sol[42];
void insert(string s){
	trie* cur = head;
	for(auto &it:s){
		int b = it - '0';
		if(!(cur->bit[b]))
			cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}
void query(trie* cur, int lvl,string &s){
	if(!cur || lvl==42)
		return;
    int oo = s[lvl]-'0';
    oo=1-oo;
    if((cur->bit[oo])){
        sol[lvl]=oo;
        query(cur->bit[oo],lvl+1,s);
    }else{
        oo=1-oo;
        sol[lvl]=oo;
        query(cur->bit[oo],lvl+1,s);
    }
}
long long int vol(long long int i){
    string s=bitset<42>(i).to_string();
    query(head,0,s);
    long long int j = 0;
    for(int i=0;i<42;i++){
        j+=sol[i]*((long long int)1<<(41-i));
    }
    return i^j;
}


void pre(){}
void solve(){
    head=new trie();
    long long int n,d=0;cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        d^=arr[i];
    }
    long long int ans = 0;
    long long int val =0;
    for(int i=0;i<n;i++){
        insert(bitset<42>(val).to_string());
        ans=max(ans,vol(d));
        d^=arr[i];
        val^=arr[i];
    }
    insert(bitset<42>(val).to_string());
    ans=max(ans,vol(d));
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
	//cout<<"Case #"<<i+1<<": ";
       	solve();
    }   
}