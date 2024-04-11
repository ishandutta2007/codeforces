uses math;
var t, i: longint;
    n, k, d1, d2, sum, lel: int64;
    chk: boolean;
procedure Work;
begin
  if (sum <= k) and ((k - sum) mod 3 = 0) and (lel + (k - sum) div 3 <= n div 3)
  then chk := true;
end;
begin
  read(t);
  for i := 1 to t do
  begin
    chk := false;
    readln(n,k,d1,d2);
    if n mod 3 = 0 then
    begin
      lel := d1 + d2;
      sum := d1 + 2*d2;
      Work;
      sum := d2 + 2*d1;
      Work;
      lel := max(d1,d2);
      sum := d1 + d2;
      Work;
      sum := 2*max(d1,d2)-min(d1,d2);
      Work;
    end;
    if chk then writeln('yes') else writeln('no');
  end;
end.