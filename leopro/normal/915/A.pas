uses
  Math;

var
  n, k, i, ans: LongInt;
  a: array [1..100] of LongInt;

begin
  read(n, k);
  ReadLn;
  For i := 1 to n do Read(a[i]);
  ReadLn;
  ans := 101;
  For i := 1 to n do
  If k mod a[i] = 0 then ans := min(ans, k div a[i]);
  WriteLn(ans);
end.