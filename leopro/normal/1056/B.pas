var
  n, m, ans, r, x: Int64;
  i, j: Int32;
  Rest: array [1..1000] of Int32;

begin
  ReadLn(n, m);
  ans := 0;     
  For i := 1 to m do Rest[i] := (i*i) mod m;
  If n >= m then
  begin
    For i := 1 to m do
      For j := 1 to m do
        If (Rest[i]+Rest[j]) mod m = 0 then ans+=1;
    ans := ans * (n div m) * (n div m);
    r := n mod m;
    x := 0;
    For i := 1 to r do
      For j := 1 to m do
        If (Rest[i]+Rest[j]) mod m = 0 then x+=1;
    x*=(2*(n div m));
    ans+=x;
  end;
  r := n mod m;
  For i := 1 to r do
      For j := 1 to r do
        If (Rest[i]+Rest[j]) mod m = 0 then ans+=1;
  WriteLn(ans);
  ReadLn;
end.