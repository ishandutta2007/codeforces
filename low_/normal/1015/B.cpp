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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s, t;
	cin>>s>>t;
	int cnts[26], cntt[26];
	for (int i=0; i<26; i++) cnts[i]=0, cntt[i]=0;
	
	for (int i=0; i<n; i++) cnts[s[i]-'a']++, cntt[t[i]-'a']++;
	for (int i=0; i<26; i++) if (cnts[i]!=cntt[i])
	{
	    cout<<-1;
	    return 0;
	}
	
	vector <int> ans={};
	
	char temp;
	for (int i=0; i<n; i++)
	{
	    for (int j=i; j<n; j++) if (s[j]==t[i])
	    {
	        for (int ij=j-1; ij>=i; ij--)
	        {
	            temp=s[ij];
	            s[ij]=s[ij+1];
	            s[ij+1]=temp;
	            ans.push_back(ij);
	        }
	        break;
	    }
	}
	cout<<ans.size()<<'\n';
	for (int i:ans) cout<<i+1<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: