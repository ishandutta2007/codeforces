program abcd;

uses
  Math;

var
  i, n, Mistake: LongInt;
  a1, a2, a3: array of LongInt;

procedure ReadArray(var a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Read(a[i]) else ReadLn(a[i]);
end;

procedure ZeroArray(var a: array of LongInt);
begin
  For i := 0 to Length(a)-1 do a[i] := 0;
end;

procedure SortArray(var a: array of LongInt);
var
  j, k, N, d, e, x: LongInt;
  b: array [0..1, 0..1048575] of LongInt;
begin
  ZeroArray(b[0]);
  For i := 0 to Length(a)-1 do b[0, i] := a[i];
  N := 2;
  While N < Length(a) do N := N*2;
  i := 1;
  x := 0;
  While i < N do
  begin
    For j := 0 to (N div (i*2))-1 do
    begin
      d := 0;
      e := 0;
      For k := 0 to i*2-1 do
      begin
        N := N;
        If (e < i) and (d < i) then
        begin
          If min(b[x, j*(i*2)+d], b[x, j*(i*2)+i+e]) =
                 b[x, j*(i*2)+d] then
          begin
            b[(x+1) mod 2, j*(i*2)+d+e] := b[x, j*(i*2)+i+e];
            e := e+1;
          end else
          begin
            b[(x+1) mod 2, j*(i*2)+d+e] := b[x, j*(i*2)+d];
            d := d+1;
          end;
        end else
        begin
          If (e < i) and (d = i) then
          begin
            b[(x+1) mod 2, j*(i*2)+d+e] := b[x, j*(i*2)+i+e];
            e := e+1;
          end;
          If (e = i) and (d < i) then
          begin
            b[(x+1) mod 2, j*(i*2)+d+e] := b[x, j*(i*2)+d];
            d := d+1;
          end;
        end;
      end;
    end;
    x := (x+1) mod 2;
    i := i*2;
  end;
  For i := 0 to Length(a)-1 do a[i] := b[x, i];
end;

begin
  ReadLn(n);
  SetLength(a1, n);
  SetLength(a2, n-1);
  SetLength(a3, n-2);

  ReadArray(a1, Length(a1));
  ReadArray(a2, Length(a2));
  ReadArray(a3, Length(a3));

  SortArray(a1);
  SortArray(a2);
  SortArray(a3);

  Mistake:=-1;
  For i := 0 to N-2 do
  begin
    If a1[i] <> a2[i] then
    begin
      Mistake := a1[i];
      break;
    end;
  end;
  If Mistake = -1 then Mistake:=a1[N-1];
  WriteLn(Mistake);

  Mistake:=-1;
  For i := 0 to N-3 do
  begin
    If a2[i] <> a3[i] then
    begin
      Mistake := a2[i];
      break;
    end;
  end;
  If Mistake = -1 then Mistake:=a2[N-2];
  WriteLn(Mistake);  
end.