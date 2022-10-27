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
#define inf 92233720368547757
#define mn 100005
#define FLN "test"

int n;
string S[mn];
bool Conv[mn][30];

class Node{
public:
	int Child[3];
	int cntw;
	
	Node()
	{
		Child[0]=Child[1]=Child[2]=-1;
		cntw=0;
	}
} Nil;

class Trie_tree{
private:
	vector <Node> Trie;
	
	int Cnt_word(int ind)
	{
		int pt1=0, pt2=0;
		for (int i=0; i<26; i++)
		{
			pt1=Trie[pt2].Child[Conv[ind][i]];
			if (pt1==-1) return 0;
			pt2=pt1;
		}
		return Trie[pt1].cntw;
	}
public:
	Trie_tree()
	{
		Trie={Nil};
	}
	
	void Add_word(int ind)
	{
		int pt1=0, pt2=0;
		for (int i=0; i<26; i++)
		{
			pt1=Trie[pt2].Child[Conv[ind][i]];
			if (pt1==-1)
			{
				pt1=Trie[pt2].Child[Conv[ind][i]]=Trie.size();
				Trie.push_back(Nil);
			}
			pt2=pt1;
		}
		Trie[pt1].cntw++;
	}
	
	int Get_ans(int ind)
	{
		int ans=Cnt_word(ind)-1;
		for (int i=0; i<26; i++) 
		{
			Conv[ind][i]=!Conv[ind][i];
			ans+=Cnt_word(ind);
			Conv[ind][i]=!Conv[ind][i];
		}
		return ans;
	}
};

Trie_tree TT;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>S[i];
		for (int j=0; j<30; j++) Conv[i][j]=0;
	}
	
	for (int i=1; i<=n; i++) for (char c:S[i]) Conv[i][c-'a']=!Conv[i][c-'a'];
	
	for (int i=1; i<=n; i++) TT.Add_word(i);
	int ans=0;
	for (int i=1; i<=n; i++) ans+=TT.Get_ans(i);
	ans=ans/2;
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_