using System;
using System.Linq;

public static class Program
{
  static long GCD(long a, long b)
  {
      return b == 0 ? a : GCD(b, a % b);
  }

    public static void Main()
    {
      var nn = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
      long a = nn[0];
      long h = nn[1];
      long w = nn[2];

      long x = h + a;
      long y = w + a;
      long g = GCD(x, y);
      x /= g;
      y /= g;

      long m = Math.Min((h + a) / (a * x), (w + a) / (a * y));
      if (m == 0 || a > h || a > w) {
        Console.WriteLine("-1");
      } else {
        Console.WriteLine(String.Format("{0:0.0000000000}", Math.Min(1.0 * (h - (x * m - 1) * a) / (x * m), 1.0 * (w - (y * m - 1) * a) / (y * m))).Replace(",", "."));
      }
    }
}