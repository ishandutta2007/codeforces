#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

class node{
public:
	int Child[26];
	node()
	{
		for (int i=0; i<26; i++) Child[i]=-1;
	}
} Nil;

int n, k;
string s;
vector <node> trie={Nil};

void add_word(string S)
{
	int p1=0, p2=0;
	for (int i=0; i<S.size(); i++)
	{
		p2=trie[p1].Child[S[i]-'a'];
		if (p2==-1)
		{
			p2=trie[p1].Child[S[i]-'a']=trie.size();
			trie.push_back(Nil);
		}
		p1=p2;
	}
}

int Loss[mn]={0}, Loss2[mn]={0};

void DFS(int u)
{
	Loss[u]=1;
    Loss2[u]=-1;
	for (int i=0; i<26; i++) if (trie[u].Child[i]!=-1) 
	{
        if (Loss2[u]==-1) Loss2[u]=1;
		DFS(trie[u].Child[i]);
		if (Loss[trie[u].Child[i]]==1) Loss[u]=0;
        if (Loss2[trie[u].Child[i]]==1) Loss2[u]=0;
	}
    if (Loss2[u]==-1) Loss2[u]=0;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	for (int i=0; i<n; i++)
	{
		cin>>s;
		add_word(s);
	}
	DFS(0);

    if (!Loss[0] && !Loss2[0]) cout<<"First";
    else if (Loss[0]) cout<<"Second";
    else if (Loss2[0])
    {
          if (k%2==1) cout<<"First";
          else cout<<"Second";
    }
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: