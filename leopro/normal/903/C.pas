var
  N, i, Ans, Max: LongInt;
  Boxes: array of LongInt;

procedure ReadArray(var a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Read(a[i]) else ReadLn(a[i]);
end;

procedure WriteArray(a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Write(a[i], ' ') else WriteLn(a[i]);
end;

procedure SortArray(var a: array of LongInt);
var
  j, k, N, plus1, plus2, x, i: LongInt;
  b: array of array of LongInt;
  First: Boolean;
begin
  N := 1;
  While N < Length(a) do N := N*2;
  SetLength(b, 2, N);
  For i := 0 to Length(a)-1 do b[0, i] := a[i];
  i := 1;
  x := 0;
  While i < N do
  begin
    For j := 0 to (N div (i*2))-1 do
    begin
      plus1 := 0;
      plus2 := 0;
      For k := 0 to i*2-1 do
      begin
        First := True;
        If (plus2 < i) and (plus1 < i) then
        begin
          If (b[x, j*(i*2)+plus1] < b[x, j*(i*2)+i+plus2]) then First := False;
        end else If (plus2 < i) and (plus1 = i) then First := False;
        If (j*(i*2)+i+plus2 > Length(a)-1) then First := True;
        If (j*(i*2)+plus1 > Length(a)-1) then First := False;

        If First then
        begin
          b[(x+1) mod 2, j*(i*2)+plus1+plus2] := b[x, j*(i*2)+plus1];
          plus1 := plus1+1;
        end else
        begin
          b[(x+1) mod 2, j*(i*2)+plus1+plus2] := b[x, j*(i*2)+i+plus2];
          plus2 := plus2+1;
        end;
      end;
    end;
    x := (x+1) mod 2;
    i := i*2;
  end;
  For i := 0 to Length(a)-1 do a[i] := b[x, i];
end;

begin
  ReadLn(N);
  SetLength(Boxes, N);
  ReadArray(Boxes, N);
  SortArray(Boxes);
  Ans := 1;
  Max := 0;
  For i := 1 to N-1 do
  begin
    If Boxes[i] = Boxes[i-1] then inc(Ans) else
    begin
      If Max < Ans then Max := Ans;
      Ans := 1;
    end;
  end;
  If Max < Ans then Max := Ans;
  WriteLn(Max);
  ReadLn;
end.