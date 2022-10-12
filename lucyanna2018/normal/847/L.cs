using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Test
{
	class Program
	{
		int[] ace;
		int ancestor(int x)
		{
			return x - ace[x] != 0 ? ace[x] = ancestor(ace[x]) : x;
		}
		void run()
		{
			int n = Convert.ToInt32(Console.ReadLine());

			Int64[] p2 = new Int64[n + 1];
			Int64 all = 0;
			p2[0] = 1;
			Int64 mod  = 750161067016189L;
			for (int i = 1; i <= n; i++)
			{
				p2[i] = p2[i - 1] * 2 % mod;
				all = (all + p2[i]) % mod;
			}


			int[][][] arr = new int[n+1][][];
			Dictionary<Int64, int>[] dict = new Dictionary<Int64, int>[n + 1];
			for (int i = 1; i <= n; i++)
			{
				String[] ss = Console.ReadLine().Split('-');
				arr[i] = new int[ss.Length][];
				int pnt = 0;
				dict[i] = new Dictionary<Int64, int>();
				foreach (String s in ss)
				{
					String[] ss1 = s.Split(':');
					int len = Convert.ToInt32(ss1[0]);
					arr[i][pnt] = new int[len];
					int pnt2 = 0;
					Int64 hash = 0;
					foreach (String s2 in ss1[1].Split(','))
					{
						arr[i][pnt][pnt2] = Convert.ToInt32(s2);
						hash = (hash + p2[arr[i][pnt][pnt2]])%mod;
						pnt2 ++;
					}
					dict[i].Add(hash, 1);
					pnt++;
				}
			}
			ace = new int[n+1];
			int[] deg = new int[n + 1];
			for (int i = 1; i <= n; i++)
				ace[i] = i;
			List<int> res = new List<int>();

			for (int i = 1; i <= n; i++)
				for(int i1 = 0; i1 < arr[i].Length; i1++){
					Int64 hash = all;
					for (int k = 0; k < arr[i][i1].Length; k++)
					{
						hash = (hash + mod - p2[arr[i][i1][k]])%mod;
					}
					for (int k = 0; k < arr[i][i1].Length; k++)
					{
						int id = arr[i][i1][k];
						if(id < i)continue;

						if(dict[id].ContainsKey(hash)){
							ace[ancestor(id)] = ancestor(i);
							res.Add(i);
							res.Add(id);
							deg[i]++;
							deg[id]++;
						}
					}
				}
			bool flag = res.Count == (n - 1) * 2;
			for (int i = 1; i <= n; i++)
			{
				if (ancestor(i) != ancestor(1))
					flag = false;
				if (deg[i] != arr[i].Length)
					flag = false;
			}
			if (flag)
			{
				bool c = true;
				Console.WriteLine(String.Format("{0}",n-1));
				foreach (int x in res)
				{
					Console.Write(String.Format("{0}{1}", x,c?' ':'\n'));
					c = !c;
				}
			}
			else
				Console.WriteLine("-1");
		}
		static void Main(string[] args)
		{
			new Program().run();
		}
	}
}