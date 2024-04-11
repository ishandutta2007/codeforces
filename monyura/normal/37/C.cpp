#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct vert
{
    vert *left,*right;
    string word;
    int lvl;
    vert()
    {
        left=right=0;
        lvl=0;
    }
};

string ins(vert *p,int ins)
{
    queue<vert*> q;
    q.push(p);
    while (!q.empty())
    {
        vert *curr=q.front();
        q.pop();
        if (curr->lvl>=ins) continue;
        if (curr->left==0 && curr->lvl<ins)
        {
            int st=curr->lvl+1;
            for (int i=st;i<=ins;i++)
            {
                vert *add=new vert;
                add->lvl=i;
                add->word=curr->word+"0";
                curr->left=add;
                curr=add;
            }
            return curr->word;
        }
        if (curr->right==0 && curr->lvl<ins)
        {
            int st=curr->lvl+1;
            for (int i=st;i<=ins;i++)
            {
                vert *add=new vert;
                add->lvl=i;
                add->word=curr->word+"1";
                curr->right=add;
                curr=add;
            }
            return curr->word;
        }
        if (curr->right!=0 && (curr->right->left!=0 || curr->right->right!=0)) q.push(curr->right);
        if (curr->left!=0 && (curr->left->left!=0 || curr->left->right!=0)) q.push(curr->left);
        
    }
    return "";  
}

struct elem
{
    int ind;
    int val;
};

bool operator<(elem &a,elem &b)
{
    return a.val<b.val;
}

int main()
{
    int n;
    vert tree;
    cin>>n;
    string *A=new string[n];
    elem *B=new elem[n];
    bool ans=true;
    for (int i=0;i<n;i++)
    {
        cin>>B[i].val;
        B[i].ind=i;
    }
    sort(B,B+n);
    for (int i=0;i<n && ans;i++)
    {
        string curr=ins(&tree,B[i].val);
        if (curr.size()==0) ans=false;
        A[B[i].ind]=curr;
    }
    if (!ans) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for (int i=0;i<n;i++)
            cout<<A[i].c_str()<<endl;
    }
    return 0;
}