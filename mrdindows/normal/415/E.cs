using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace Codeforces.TaskE
{
    public class Task
    {
        public static void Main()
        {
            var task = new Task();
            task.Solve();
        }

        private int[] A;
        private long[,] Dp;

        void MergeSort(int l, int r, int depth)
        {
            if (l >= r) return;
            var m = (l + r)/2;
            if (l < m) MergeSort(l, m, depth-1);
            if (m + 1 < r) MergeSort(m + 1, r, depth - 1);

            var j = m + 1;
            for (var i = l; i <= m; i++)
            {
                while (j <= r && A[i] >= A[j]) j++;
                Dp[depth, 1] += r - j + 1;
            }

            j = l;
            for (var i = m + 1; i <= r; i++)
            {
                while (j <= m && A[i] >= A[j]) j++;
                Dp[depth, 0] += m - j + 1;
            }

            Array.Sort(A, l, r - l + 1);
        }

        void Solve()
        {
            var n = int.Parse(Console.ReadLine());
            A = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Dp = new long[n+1, 2];

            MergeSort(0, (1<<n) - 1, n);

            Console.Write("");

            Console.ReadLine();
            var Q = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var output = new List<long>();
            foreach (var q in Q)
            {
                for (var i = 1; i <= q; i++)
                    Dp[i, 0] = Interlocked.Exchange(ref Dp[i, 1], Dp[i, 0]);

                var result = 0L;
                for (var i = 1; i <= n; i++)
                    result += Dp[i, 0];
                output.Add(result);
            }
            Console.Write(string.Join("\n", output));
        }
    }
}