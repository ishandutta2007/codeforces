#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod[2]={1'000'000'000+7,999500011},base[2]={29,31};

int which;

string s,t;

int n,q;

long long mem_2[nmax];

string seen[24];

vector<int> pref[2][24];

vector<int> pref_extra[2];

long long mem_pw_base[2][nmax];

vector< pair<int,int> > pref_by_letter[26];

int ask(int l,int r,int letter)
{
    //cout<<"\t\t ask "<<l<<" "<<r<<" "<<letter<<endl;

    if(l>r)return 0;

    int u=lower_bound(pref_by_letter[letter].begin(),pref_by_letter[letter].end(),make_pair(l,0))-pref_by_letter[letter].begin();

    int v=lower_bound(pref_by_letter[letter].begin(),pref_by_letter[letter].end(),make_pair(r+1,0))-pref_by_letter[letter].begin();

    //cout<<"u= "<<u<<" v= "<<v<<endl;

    v--;

    if(u>v)return 0;

    long long ret=(mod[0]+pref_by_letter[letter][v].second-(u?pref_by_letter[letter][u-1].second:0))%mod[0];
    return ret;
}

int ask_pref(int t,int where,int l,int r)
{
    //cout<<"ask pref "<<t<<" "<<where<<" "<<l<<" "<<r<<" -> "<<pref[t][where].size()<<endl;

    long long ret=pref[t][where][r];

    //cout<<" ret= "<<ret<<endl;

    if(l)ret=(ret-pref[t][where][l-1]*mem_pw_base[t][r-l+1])%mod[t];

    ret=(ret+mod[t])%mod[t];

    return ret;
}

int ask_pref_extra(int t,int l,int r)
{
    long long ret=pref_extra[t][r];

    if(l)ret=(ret-pref_extra[t][l-1]*mem_pw_base[t][r-l+1])%mod[t];

    ret=(ret+mod[t])%mod[t];

    //cout<<"t= "<<t<<" l= "<<l<<" r= "<<r<<endl;

    return ret;
}
bool test(int l_extra,int r_extra,int where,int l_seen,int r_seen)
{
    //cout<<"test "<<l_extra<<" "<<r_extra<<" "<<where<<" "<<l_seen<<" "<<r_seen<<endl;

    if(l_extra>r_extra)return 1;

    for(int t=0;t<2;t++)
    {
        int p=ask_pref_extra(t,l_extra,r_extra);

        //cout<<"p= "<<p;

        int q=ask_pref(t,where,l_seen,r_seen);

        //cout<<" q= "<<q<<endl;

        if(p!=q)return 0;
    }
    return 1;
}
int eval(string extra)
{
    //cout<<"EVAL "<<extra<<endl;

    if(extra.size()==0)return mem_2[which];

    int lg=0;

    while(seen[lg].size()<=extra.size()&&lg<which-1)lg++;

    if(seen[lg].size()<extra.size())return 0;

    pref_extra[0]={};
    pref_extra[1]={};

    long long mem[2]={0,0};

    for(int j=0;j<extra.size();j++)
    {
        mem[0]=(mem[0]*base[0]+extra[j]-'a'+1)%mod[0];
        mem[1]=(mem[1]*base[1]+extra[j]-'a'+1)%mod[1];

        pref_extra[0].push_back(mem[0]);
        pref_extra[1].push_back(mem[1]);
    }

    //cout<<"ok 100 "<<seen[lg]<<" lg= "<<lg<<endl;

    long long ret=0;

    for(int j=extra.size()-1;j<seen[lg].size();j++)
    {
        if(test(0,extra.size()-1,lg,j-extra.size()+1,j))
        {
            if(which-lg-1>=0)ret=(ret+mem_2[which-lg-1])%mod[0];
        }
    }

    //cout<<"extra= "<<extra<<" ret= "<<ret<<endl;

    //cout<<"ok 112"<<endl;

    for(int j=0;j<extra.size();j++)
    {
        //cout<<"j= "<<j<<endl;

        long long coeff=ask(lg+1,which-1,extra[j]-'a');

        //cout<<"coeff= "<<coeff<<endl;

        if(test(j+1,extra.size()-1,lg,0,extra.size()-j-2)&&test(0,j-1,lg,seen[lg].size()-j,seen[lg].size()-1));
        else coeff=0;

        coeff=coeff*mem_2[which]%mod[0];

        //cout<<"\t "<<j<<" -> "<<coeff<<endl;

        ret=(ret+coeff)%mod[0];
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    mem_2[0]=1;
    for(int i=1;i<nmax;i++)mem_2[i]=mem_2[i-1]*2%mod[0];

    for(int t=0;t<2;t++)
    {
        mem_pw_base[t][0]=1;

        for(int j=1;j<nmax;j++)
            mem_pw_base[t][j]=mem_pw_base[t][j-1]*base[t]%mod[t];
    }

    cin>>n>>q;

    cin>>s>>t;

    /*
    n=1e5;
    q=1e5;

    for(int i=1;i<=100;i++)s.push_back('a');

    for(int i=1;i<=n;i++)
    {
        t.push_back('a');
    }
    */

    seen[0].push_back(t[0]);

    for(int i=0;i<t.size()&&i<=20;i++)
    {
        if(i)seen[i]=seen[i-1]+t[i]+seen[i-1];

        //cout<<i<<" -> "<<seen[i]<<endl;

        long long mem[2]={0,0};

        for(int j=0;j<seen[i].size();j++)
        {
            mem[0]=(mem[0]*base[0]+seen[i][j]-'a'+1)%mod[0];
            mem[1]=(mem[1]*base[1]+seen[i][j]-'a'+1)%mod[1];

            pref[0][i].push_back(mem[0]);
            pref[1][i].push_back(mem[1]);

            //cout<<i<<" "<<0<<" "<<j<<" -> "<<mem[0]<<endl;
        }

        //cout<<i<<" -> "<<seen[i].size()<<" "<<pref[i][0].size()<<" "<<pref[i][1].size()<<endl;
    }

    long long i_2=(mod[0]+1)/2;

    long long mem_inv=1;

    for(int i=0;i<t.size();i++)
    {
        mem_inv=mem_inv*i_2%mod[0];

        int CUR=0;

        if(pref_by_letter[t[i]-'a'].size())
            CUR=pref_by_letter[t[i]-'a'].back().second;

        CUR=(CUR+mem_inv)%mod[0];

        pref_by_letter[t[i]-'a'].push_back({i,CUR});
    }
    for(int i=1;i<=q;i++)
    {
        string cur;

        cin>>which>>cur;

        long long outp=0;

        int cur_mod=s.size()+1;

        for(int start=0;start<cur_mod;start++)
        {
            bool ok=1;

            //cout<<"start= "<<start<<endl;

            string extra="";

            for(int j=0;j<cur.size()&&ok;j++)
            {
                int should=(start+j)%cur_mod;

                if(should==cur_mod-1)extra.push_back(cur[j]);
                else if(cur[j]!=s[should])
                {
                    //cout<<"start= "<<start<<" is wrong"<<endl;
                    ok=0;
                }
            }

            //cout<<"start= "<<start<<" ok= "<<ok<<" extra= "<<extra<<endl;

            if(ok==0)continue;

            outp=(outp+eval(extra))%mod[0];

            //cout<<"outp= "<<outp<<endl;
        }

        cout<<outp<<endl;
    }
    return 0;
}