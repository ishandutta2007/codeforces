uses
  Math;

var
  n, i, x, ans: LongInt;
  
begin
  ReadLn(n);
  ans := -10000000;
  For i := 1 to n do
  begin
    Read(x);
    If x >= 0 then
    begin
      If round(sqrt(x)) <> sqrt(x) then ans := max(ans, x);
    end else ans := max(ans, x);
  end;
  WriteLn(ans);
  ReadLn;
end.