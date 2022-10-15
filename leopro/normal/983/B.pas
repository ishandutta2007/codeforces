var
  N, i, j, q, l, r: Int32;
  a: array [1..5000, 1..5000] of Int32;

function max(a, b, c: Int32): Int32;
begin
  If a > b then Result := a else Result := b;
  If c > Result then Result := c;
end;

begin
  ReadLn(N);
  For i := 1 to N do Read(a[1, i]);
  ReadLn;

  For i := 2 to N do
  begin
    For j := 1 to N-i+1 do
    begin
      a[i, j] := a[i-1, j] xor a[i-1, j+1];
    end;
  end;
  For i := 2 to N do
  begin
    For j := 1 to N-i+1 do
    begin
      a[i, j] := max(a[i-1, j], a[i-1, j+1], a[i, j]);
    end;
  end;
  ReadLn(q);
  For i := 1 to q do
  begin
    ReadLn(l, r);
    WriteLn(a[r-l+1, l]);
  end;
end.