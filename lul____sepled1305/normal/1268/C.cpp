#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,i,j;
int a[N];
int rev[N];
long long cur_inv, mov;

struct fenwickTree
{
private:
    int n;
    vector<long long> v;
public:
    fenwickTree(int n)
    {
        this -> n = n;
        int r;
        for(r=0;r<n;r++)
            v.push_back(0LL);
    }
    void add(int idx, int val)
    {
        for(;idx<n;idx = idx|(idx+1))
            v[idx]+=val;
    }
    long long sum(int r)
    {
        long long cur = 0LL;
        for(; r>=0;r = (r&(r+1))-1)
            cur+=v[r];
        return cur;
    }
    long long sum(int l,int r)
    {
        return sum(r) - sum(l-1);
    }
};

int b_search(long long tar, fenwickTree &placeTree)
{
    int mini = 0, maxi = n-1;
    while(mini<maxi)
    {
        int mid = mini+maxi >>1;
        if(mini == mid)
        {
            if(placeTree.sum(mini)<tar)
                mini = maxi;
            else
                maxi = mini;
        }
        else
        {
            long long cur = placeTree.sum(mid);
            if(cur<tar)
                mini = mid+1;
            else
                maxi = mid;
        }
    }
    return mini;
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i],rev[a[i]-1]=i;

    fenwickTree placeTree(n);
    fenwickTree valTree(n);

    for(i=0;i<n;i++)
    {
        mov = 0;
        placeTree.add(rev[i],1);
        valTree.add(rev[i],rev[i]);
        cur_inv+=placeTree.sum(rev[i],n-1)-1;
        int mid = b_search(i/2 +1, placeTree);
        mov = 1LL*mid*placeTree.sum(mid);
        if(mid!=n-1)
            mov -= 1LL*mid*placeTree.sum(mid+1,n-1);
        if(mid!=n-1)
            mov += 1LL*valTree.sum(mid+1,n-1);
        mov-= 1LL*valTree.sum(mid);
        i++;
        if(i%2==1)
            mov-=1LL*(i/2)*(i/2+1);
        else
            mov-=1LL*(i/2)*(i/2);
        i--;
        cout<<cur_inv+mov<<" ";
    }

    return 0;
}