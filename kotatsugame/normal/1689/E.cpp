#include<iostream>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace std;
int T,N,A[2000];
int cnt[30][30],cB[30];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int zero=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			if(A[i]==0)
			{
				A[i]=1;
				zero++;
			}
		}
		{//0
			atcoder::dsu uf(N);
			int mg=0;
			for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)if(A[i]&A[j])
			{
				if(!uf.same(i,j))mg++;
				uf.merge(i,j);
			}
			if(mg==N-1)
			{
				cout<<zero<<"\n";
				for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
				continue;
			}
		}
		{//1
			for(int i=0;i<30;i++)for(int j=0;j<30;j++)cnt[i][j]=0;
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<30;j++)if(A[i]>>j&1)
				{
					for(int k=0;k<30;k++)if(A[i]>>k&1)cnt[j][k]++;
				}
			}
			bool fn=false;
			for(int i=0;!fn&&i<N;i++)
			{
				for(int d=-1;d<=1;d+=2)
				{
					if(A[i]+d<=0||A[i]+d>=(1<<30))continue;
					for(int j=0;j<30;j++)if(A[i]>>j&1)
					{
						for(int k=0;k<30;k++)if(A[i]>>k&1)cnt[j][k]--;
					}
					A[i]+=d;
					for(int j=0;j<30;j++)
					{
						if(A[i]>>j&1)
						{
							for(int k=0;k<30;k++)if(A[i]>>k&1)cnt[j][k]++;
						}
						cB[j]=0;
						for(int k=0;k<30;k++)if(cnt[j][k]>0)cB[j]|=1<<k;
					}
					int t=__builtin_ctz(A[i]);
					t=1<<t;
					while(true)
					{
						int nxt=t;
						for(int j=0;j<30;j++)if(t>>j&1)nxt|=cB[j];
						if(nxt==t)break;
						t=nxt;
					}
					bool ok=true;
					for(int j=0;j<30;j++)if(cnt[j][j]>0&&!(t>>j&1))
					{
						ok=false;
						break;
					}
					if(ok)
					{
						fn=true;
						break;
					}
					for(int j=0;j<30;j++)if(A[i]>>j&1)
					{
						for(int k=0;k<30;k++)if(A[i]>>k&1)cnt[j][k]--;
					}
					A[i]-=d;
					for(int j=0;j<30;j++)if(A[i]>>j&1)
					{
						for(int k=0;k<30;k++)if(A[i]>>k&1)cnt[j][k]++;
					}
				}
			}
			if(fn)
			{
				cout<<zero+1<<"\n";
				for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
				continue;
			}
		}
		{//2
			int mt=-1,mid=-1,mid2;
			for(int i=0;i<N;i++)
			{
				int t=__builtin_ctz(A[i]);
				if(mt<t)
				{
					mt=t;
					mid=i;
				}
				else if(mt==t)
				{
					mid2=i;
				}
			}
			A[mid]--;
			A[mid2]++;
			cout<<zero+2<<"\n";
			for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
		}
	}
}