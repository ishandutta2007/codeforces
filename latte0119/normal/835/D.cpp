#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

class SuffixArray{
    void create_begin_bucket(vector<int>&v,vector<int>&bucket){
        fill(bucket.begin(),bucket.end(),0);
        for(int i=0;i<v.size();i++)bucket[v[i]]++;
        int sum=0;
        for(int i=0;i<bucket.size();i++){bucket[i]+=sum;swap(sum,bucket[i]);}
    }

    void create_end_bucket(vector<int>&v,vector<int>&bucket){
        fill(bucket.begin(),bucket.end(),0);
        for(int i=0;i<v.size();i++)bucket[v[i]]++;
        for(int i=1;i<bucket.size();i++)bucket[i]+=bucket[i-1];
    }

    void induced_sort(vector<int>&v,vector<int>&sa,int mv,vector<int>&bucket,vector<int>&is_l){
        create_begin_bucket(v,bucket);
        for(int i=0;i<v.size();i++)if(sa[i]>0&&is_l[sa[i]-1])sa[bucket[v[sa[i]-1]]++]=sa[i]-1;
    }

    void invert_induced_sort(vector<int>&v,vector<int>&sa,int mv,vector<int>&bucket,vector<int>&is_l){
        create_end_bucket(v,bucket);
        for(int i=v.size()-1;i>=0;i--)if(sa[i]>0&&!is_l[sa[i]-1])sa[--bucket[v[sa[i]-1]]]=sa[i]-1;
    }

    vector<int>sa_is(vector<int>v,int mv){
        if(v.size()==1)return vector<int>(1,0);

        vector<int>is_l(v.size());
        vector<int>bucket(mv+1);
        vector<int>sa(v.size(),-1);
        auto is_lms=[&](int x)->bool{return x>0&&is_l[x-1]&&!is_l[x];};

        is_l[v.size()-1]=0;
        for(int i=v.size()-2;i>=0;i--)is_l[i]=v[i]>v[i+1]||(v[i]==v[i+1]&&is_l[i+1]);
        create_end_bucket(v,bucket);
        for(int i=0;i<v.size();i++)if(is_lms(i))sa[--bucket[v[i]]]=i;
        induced_sort(v,sa,mv,bucket,is_l);
        invert_induced_sort(v,sa,mv,bucket,is_l);

        int cur=0;
        vector<int>order(v.size());
        for(int i=0;i<v.size();i++)if(is_lms(i))order[i]=cur++;

        vector<int>next_v(cur);
        cur=-1;
        int prev=-1;
        for(int i=0;i<v.size();i++){
            if(!is_lms(sa[i]))continue;
            bool diff=false;
            for(int d=0;d<v.size();d++){
                if(prev==-1||v[sa[i]+d]!=v[prev+d]||is_l[sa[i]+d]!=is_l[prev+d]){
                    diff=true;
                    break;
                }
                else if(d>0&&is_lms(sa[i]+d))break;
            }
            if(diff){cur++;prev=sa[i];}
            next_v[order[sa[i]]]=cur;
        }

        vector<int>re_order(next_v.size());
        for(int i=0;i<v.size();i++)if(is_lms(i))re_order[order[i]]=i;
        vector<int>next_sa=sa_is(next_v,cur);
        create_end_bucket(v,bucket);
        for(int i=0;i<sa.size();i++)sa[i]=-1;
        for(int i=next_sa.size()-1;i>=0;i--)sa[--bucket[v[re_order[next_sa[i]]]]]=re_order[next_sa[i]];
        induced_sort(v,sa,mv,bucket,is_l);
        invert_induced_sort(v,sa,mv,bucket,is_l);
        return sa;
    }

    void sa_is(string &s){
        vector<int>v(s.size()+1);
        for(int i=0;i<s.size();i++)v[i]=s[i];
        sa=sa_is(v,*max_element(v.begin(),v.end()));
    }

    void construct_lcp(){
        lcp.resize(s.size());
        rank.resize(s.size()+1);
        int n=s.size();
        for(int i=0;i<=n;i++)rank[sa[i]]=i;
        int h=0;
        lcp[0]=0;
        for(int i=0;i<n;i++){
            int j=sa[rank[i]-1];

            if(h>0)h--;
            for(;j+h<n&&i+h<n;h++){
                if(s[j+h]!=s[i+h])break;
            }
            lcp[rank[i]-1]=h;
        }
    }

    struct segtree{
        int N;
        vector<int>dat;
        void init(vector<int> &v){
            for(N=1;N<v.size();N<<=1);
            dat.resize(N*2,1001001001);
            for(int i=0;i<v.size();i++)dat[i+N-1]=v[i];
            for(int i=N-2;i>=0;i--)dat[i]=min(dat[i*2+1],dat[i*2+2]);
        }
        int get_min(int a,int b,int k,int l,int r){
            if(r<=a||b<=l)return 1001001001;
            if(a<=l&&r<=b)return dat[k];
            return min(get_min(a,b,k*2+1,l,(l+r)/2),get_min(a,b,k*2+2,(l+r)/2,r));
        }
        int get_min(int a,int b){return get_min(a,b,0,0,N);}
    };
    class sparse_table{
        vector<vector<int> >st;
    public:
        void init(vector<int>vec){
            int b;
            for(b=0;(1<<b)<=vec.size();b++);
            st.assign(b,vector<int>(1<<b));
            for(int i=0;i<vec.size();i++)st[0][i]=vec[i];

            for(int i=1;i<b;i++){
                for(int j=0;j+(1<<i)<=(1<<b);j++){
                    st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
                }
            }
        }
        int get_min(int l,int r){
            assert(l<r);
            int b=32-__builtin_clz(r-l)-1;
            return min(st[b][l],st[b][r-(1<<b)]);
        }
        sparse_table(){}
        sparse_table(vector<int>vec){init(vec);}
    };
public:
    sparse_table st;
    string s;
    vector<int>sa,lcp,rank;
    void init(string &t){
        s=t;
        sa_is(s);
        construct_lcp();
        st.init(lcp);
    }
    SuffixArray(string &t){init(t);}
    SuffixArray(){}

    bool contain(string &t){
        int lb=0,ub=s.size();
        while(ub-lb>1){
            int mid=(lb+ub)/2;
            if(s.compare(sa[mid],t.size(),t)<0)lb=mid;
            else ub=mid;
        }
        return s.compare(sa[ub],t.size(),t)==0;
    }

    int get_lcp(int i,int j){
        assert(i!=j);
        if(rank[i]>rank[j])swap(i,j);
        return st.get_min(rank[i],rank[j]);
    }
    int operator[](const int idx)const{
        return sa[idx];
    }
};
const int INF=1001001001;

int dp[5010][5010];


int ans[5555];
signed main(){
    string S;
    cin>>S;
    string T=S;
    reverse(all(T));
    string ST=S+"*"+T;
    int N=S.size();
    SuffixArray sa(ST);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<=N;j++){
            if(sa.get_lcp(i,2*N+1-j)>=j-i){
                dp[i][j]=1;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<=N;j++){
            if((j-i)%2==0){
                if(sa.get_lcp(i,i+(j-i)/2)>=(j-i)/2&&dp[i][i+(j-i)/2])dp[i][j]=dp[i][i+(j-i)/2]+1;
            }
            else{
                if(sa.get_lcp(i,i+(j-i)/2+1)>=(j-i)/2&&dp[i][i+(j-i)/2])dp[i][j]=dp[i][i+(j-i)/2]+1;
            }
            ans[dp[i][j]]++;
        }
    }

    for(int i=N;i>0;i--)ans[i-1]+=ans[i];
    rep(i,N){
        if(i)cout<<" ";cout<<ans[i+1];
    }cout<<endl;
    return 0;
}