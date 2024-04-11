#include <bits/stdc++.h>

using namespace std;

struct node
{
    node* l;
    node* r;
    int val;
};

int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a;
        cin>>a;
        node* pz=new node;
        pz->l=pz->r=NULL;
        pz->val=a;
        int ok=1;
        for(i=2;i<=n;++i)
        {
            cin>>a;
            if(a>pz->val)
            {
                if(pz->r == NULL)
                {
                    node* npz=new node;
                    npz->l=pz->l;
                    if(pz->l != NULL)
                        pz->l->r=npz;
                    pz->l=npz;
                    npz->r=pz;
                    npz->val=pz->val;
                    pz->val=a;
                }
                else
                {
                    if(pz->r->val > a)
                    {
                        node* npz=new node;
                        npz->l=pz->l;
                        if(pz->l != NULL)
                            pz->l->r=npz;
                        pz->l=npz;
                        npz->r=pz;
                        npz->val=pz->val;
                        pz->val=a;
                    }
                    else if(pz->r->val == a)
                    {
                        pz->r=pz->r->r;
                        if(pz->r != NULL)
                            pz->r->l=pz;
                        node* npz=new node;
                        npz->l=pz->l;
                        if(pz->l != NULL)
                            pz->l->r=npz;
                        pz->l=npz;
                        npz->r=pz;
                        npz->val=pz->val;
                        pz->val=a;
                    }
                    else ok=0;
                }
            }
            else if(a<pz->val)
            {
                if(pz->l == NULL)
                {
                    node* npz=new node;
                    npz->r=pz->r;
                    if(pz->r != NULL)
                        pz->r->l=npz;
                    pz->r=npz;
                    npz->l=pz;
                    npz->val=pz->val;
                    pz->val=a;
                }
                else
                {
                    if(pz->l->val < a)
                    {
                        node* npz=new node;
                        npz->r=pz->r;
                        if(pz->r != NULL)
                            pz->r->l=npz;
                        pz->r=npz;
                        npz->l=pz;
                        npz->val=pz->val;
                        pz->val=a;
                    }
                    else if(pz->l->val == a)
                    {
                        pz->l=pz->l->l;
                        if(pz->l != NULL)
                            pz->l->r=pz;
                        node* npz=new node;
                        npz->r=pz->r;
                        if(pz->r != NULL)
                            pz->r->l=npz;
                        pz->r=npz;
                        npz->l=pz;
                        npz->val=pz->val;
                        pz->val=a;
                    }
                    else ok=0;
                }
            }
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}