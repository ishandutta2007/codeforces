program Project1;

var
  k, i, n, j, max: LongInt;
  a, b: array [0..11] of LongInt;

begin
  ReadLn(k);
  For i := 0 to 11 do If i < 11 then Read(a[i]) else ReadLn(a[i]);
  For j := 11 downto 0 do
  begin
    max := a[0];
    n := 0;
    For i := 0 to j do If max > a[i] then begin max := a[i]; n := i end;
    b[11-j] := a[n];   a[n] := a[j];
  end;
  n := 0;
  For i := 11 downto 0 do
  begin
    n := n+b[i];
    If k <= n then
    begin
      n := 11-i+1;
      Break;
    end;
    If i = 0 then n := -1;
  end;
  If k = 0 then n := 0;
  WriteLn(n);
end.