uses
Math;

var
  n, k, i, j, b, c, ans: Int32;
  a, a_: array [1..100] of Int32;

begin
  ReadLn(n, k);
  ans := 0;
  For i := 1 to n do Read(a[i]);
  ReadLn;
  For j := 1 to k do
  begin
    For i := 1 to n do a_[i] := a[i];     
    i := j;
    While (i <= n) do
    begin
      a_[i] := 0;
      i += k;
    end;
    b := 0;
    c := 0;
    For i := 1 to n do
      If a_[i] = 1 then b += 1 else if a_[i] = -1 then c += 1;
    ans := max(ans, abs(b - c));
  end;
  WriteLn(ans);  readln;
end.