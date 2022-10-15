uses
Math;

var
  n, m, i, j: Int32;
  A1, G1, C1, T1: array [1..300000] of Int32;
  A2, G2, C2, T2: array [1..300000] of Int32;
  A1o, G1o, C1o, T1o: array [1..300000] of Int32;
  A2o, G2o, C2o, T2o: array [1..300000] of Int32;
  A1e, G1e, C1e, T1e: array [1..300000] of Int32;
  A2e, G2e, C2e, T2e: array [1..300000] of Int32;
  c: Char;
  Field, OutPutField: array of array of Char;
  AG1, AC1, AT1, GC1, GT1, CT1: Int32;
  AG2, AC2, AT2, GC2, GT2, CT2: Int32;
  minimum: Int32;
  FirstIsFirst: Boolean;

function min_: Int32;
var
  a1, a2: Int32;
begin
  a1 := min(min(min(min(min(AG1, AC1), AT1), GC1), GT1), CT1);
  a2 := min(min(min(min(min(AG2, AC2), AT2), GC2), GT2), CT2);
  Result := min(a1, a2);
end;

begin
  Textrec(Output).FlushFunc:=nil;
  ReadLn(n, m);
  SetLength(Field, n+1, m+1);
  SetLength(OutPutField, n+1, m+1);
  For i := 1 to n do
  begin
    For j := 1 to m do
    begin
      Read(c);
      Field[i, j] := c;
    end;
    ReadLn;
  end;
  AG1 := 0;
  AC1 := 0;
  AT1 := 0;
  GC1 := 0;
  GT1 := 0;
  CT1 := 0;
  AG2 := 0;
  AC2 := 0;
  AT2 := 0;
  GC2 := 0;
  GT2 := 0;
  CT2 := 0;
  For i := 1 to n do A1o[i] := 0;
  For j := 1 to m do A2o[j] := 0;
  For i := 1 to n do G1o[i] := 0;
  For j := 1 to m do G2o[j] := 0;
  For i := 1 to n do C1o[i] := 0;
  For j := 1 to m do C2o[j] := 0;
  For i := 1 to n do T1o[i] := 0;
  For j := 1 to m do T2o[j] := 0;
  For i := 1 to n do A1e[i] := 0;
  For j := 1 to m do A2e[j] := 0;
  For i := 1 to n do G1e[i] := 0;
  For j := 1 to m do G2e[j] := 0;
  For i := 1 to n do C1e[i] := 0;
  For j := 1 to m do C2e[j] := 0;
  For i := 1 to n do T1e[i] := 0;
  For j := 1 to m do T2e[j] := 0;
  For i := 1 to n do
  begin
    For j := 1 to m do
    begin
      If j mod 2 = 0 then
      begin
        Case Field[i, j] of
        'A': A1e[i] += 1;
        'G': G1e[i] += 1;
        'C': C1e[i] += 1;
        'T': T1e[i] += 1;
        end;
      end else
      begin
        Case Field[i, j] of
        'A': A1o[i] += 1;
        'G': G1o[i] += 1;
        'C': C1o[i] += 1;
        'T': T1o[i] += 1;
        end;
      end;
      If i mod 2 = 0 then
      begin
        Case Field[i, j] of
        'A': A2e[j] += 1;
        'G': G2e[j] += 1;
        'C': C2e[j] += 1;
        'T': T2e[j] += 1;
        end;
      end else
      begin
        Case Field[i, j] of
        'A': A2o[j] += 1;
        'G': G2o[j] += 1;
        'C': C2o[j] += 1;
        'T': T2o[j] += 1;
        end;
      end;
    end;
  end;
  For i := 1 to n do A1[i] := A1o[i] + A1e[i];
  For i := 1 to n do G1[i] := G1o[i] + G1e[i];
  For i := 1 to n do C1[i] := C1o[i] + C1e[i];
  For i := 1 to n do T1[i] := T1o[i] + T1e[i];
  For i := 1 to m do A2[i] := A2o[i] + A2e[i];
  For i := 1 to m do G2[i] := G2o[i] + G2e[i];
  For i := 1 to m do C2[i] := C2o[i] + C2e[i];
  For i := 1 to m do T2[i] := T2o[i] + T2e[i];
  For i := 1 to n do
  begin
    If i mod 2 = 1 then
    begin
      AG1 += min(abs(A1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + A1o[i] + G1e[i] + C1[i] + T1[i],
                 abs(G1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + G1o[i] + C1[i] + T1[i]) div 2;
      AC1 += min(abs(A1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + A1o[i] + C1e[i] + G1[i] + T1[i],
                 abs(C1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + C1o[i] + G1[i] + T1[i]) div 2;
      AT1 += min(abs(A1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + A1o[i] + T1e[i] + C1[i] + G1[i],
                 abs(T1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + T1o[i] + C1[i] + G1[i]) div 2;
      GC1 += min(abs(G1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + G1o[i] + C1e[i] + A1[i] + T1[i],
                 abs(C1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + G1e[i] + C1o[i] + A1[i] + T1[i]) div 2;
      GT1 += min(abs(G1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + G1o[i] + T1e[i] + C1[i] + A1[i],
                 abs(T1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + G1e[i] + T1o[i] + C1[i] + A1[i]) div 2;
      CT1 += min(abs(C1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + C1o[i] + T1e[i] + A1[i] + G1[i],
                 abs(T1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + C1e[i] + T1o[i] + A1[i] + G1[i]) div 2;
    end else
    begin
      CT1 += min(abs(A1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + A1o[i] + G1e[i] + C1[i] + T1[i],
                 abs(G1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + G1o[i] + C1[i] + T1[i]) div 2;
      GT1 += min(abs(A1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + A1o[i] + C1e[i] + G1[i] + T1[i],
                 abs(C1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + C1o[i] + G1[i] + T1[i]) div 2;
      GC1 += min(abs(A1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + A1o[i] + T1e[i] + C1[i] + G1[i],
                 abs(T1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + T1o[i] + C1[i] + G1[i]) div 2;
      AT1 += min(abs(G1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + G1o[i] + C1e[i] + A1[i] + T1[i],
                 abs(C1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + G1e[i] + C1o[i] + A1[i] + T1[i]) div 2;
      AC1 += min(abs(G1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + G1o[i] + T1e[i] + C1[i] + A1[i],
                 abs(T1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + G1e[i] + T1o[i] + C1[i] + A1[i]) div 2;
      AG1 += min(abs(C1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + C1o[i] + T1e[i] + A1[i] + G1[i],
                 abs(T1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + C1e[i] + T1o[i] + A1[i] + G1[i]) div 2;
    end;
  end;
  For j := 1 to m do
  begin
    If j mod 2 = 1 then
    begin
      AG2 += min(abs(A2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + A2o[j] + G2e[j] + C2[j] + T2[j],
                 abs(G2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + G2o[j] + C2[j] + T2[j]) div 2;
      AC2 += min(abs(A2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + A2o[j] + C2e[j] + G2[j] + T2[j],
                 abs(C2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + C2o[j] + G2[j] + T2[j]) div 2;
      AT2 += min(abs(A2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + A2o[j] + T2e[j] + C2[j] + G2[j],
                 abs(T2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + T2o[j] + C2[j] + G2[j]) div 2;
      GC2 += min(abs(G2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + G2o[j] + C2e[j] + A2[j] + T2[j],
                 abs(C2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + G2e[j] + C2o[j] + A2[j] + T2[j]) div 2;
      GT2 += min(abs(G2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + G2o[j] + T2e[j] + C2[j] + A2[j],
                 abs(T2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + G2e[j] + T2o[j] + C2[j] + A2[j]) div 2;
      CT2 += min(abs(C2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + C2o[j] + T2e[j] + A2[j] + G2[j],
                 abs(T2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + C2e[j] + T2o[j] + A2[j] + G2[j]) div 2;
    end else
    begin
      CT2 += min(abs(A2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + A2o[j] + G2e[j] + C2[j] + T2[j],
                 abs(G2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + G2o[j] + C2[j] + T2[j]) div 2;
      GT2 += min(abs(A2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + A2o[j] + C2e[j] + G2[j] + T2[j],
                 abs(C2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + C2o[j] + G2[j] + T2[j]) div 2;
      GC2 += min(abs(A2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + A2o[j] + T2e[j] + C2[j] + G2[j],
                 abs(T2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + T2o[j] + C2[j] + G2[j]) div 2;
      AT2 += min(abs(G2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + G2o[j] + C2e[j] + A2[j] + T2[j],
                 abs(C2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + G2e[j] + C2o[j] + A2[j] + T2[j]) div 2;
      AC2 += min(abs(G2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + G2o[j] + T2e[j] + C2[j] + A2[j],
                 abs(T2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + G2e[j] + T2o[j] + C2[j] + A2[j]) div 2;
      AG2 += min(abs(C2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + C2o[j] + T2e[j] + A2[j] + G2[j],
                 abs(T2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + C2e[j] + T2o[j] + A2[j] + G2[j]) div 2;
    end;
  end;
  minimum := min_;
  If AG1 = minimum then
  begin
    For i := 1 to n do
    begin
      If i mod 2 = 1 then FirstIsFirst := (abs(A1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + A1o[i] + G1e[i] >
         abs(G1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + G1o[i]) else
                          FirstIsFirst := (abs(C1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + C1o[i] + T1e[i] >
         abs(T1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + C1e[i] + T1o[i]);
      For j := 1 to m do
      begin
        If (i mod 2 = 1) then
        begin
          If (FirstIsFirst) xor not(j mod 2 = 1) then OutputField[i, j] := ('A') else OutputField[i, j] := ('G');
        end else
        begin
          If (FirstIsFirst) xor not(j mod 2 = 1) then OutputField[i, j] := ('C') else OutputField[i, j] := ('T');
        end;
      end;
    end;
  end;
  If AC1 = minimum Then
  begin
    For i := 1 To n do
    begin
      If i mod 2 = 1 Then FirsTIsFirsT := (Abs(A1e[i] - (m div 2)) + Abs(C1o[i] - (m - (m div 2))) + A1o[i] + C1e[i] >
         Abs(C1e[i] - (m div 2)) + Abs(A1o[i] - (m - (m div 2))) + A1e[i] + C1o[i]) else
                          FirsTIsFirsT := (Abs(G1e[i] - (m div 2)) + Abs(T1o[i] - (m - (m div 2))) + G1o[i] + T1e[i] >
         Abs(T1e[i] - (m div 2)) + Abs(G1o[i] - (m - (m div 2))) + G1e[i] + T1o[i]);
      For j := 1 To m do
      begin
        If (i mod 2 = 1) Then
        begin
          If (FirsTIsFirsT) xor not(j mod 2 = 1) Then OutputField[i, j] := ('A') else OutputField[i, j] := ('C');
        end else
        begin
          If (FirsTIsFirsT) xor not(j mod 2 = 1) Then OutputField[i, j] := ('G') else OutputField[i, j] := ('T');
        end;
      end;
    end;
  end;
  If AT1 = minimum then
  begin
    For i := 1 to n do
    begin
      If i mod 2 = 1 then FirstIsFirst := (Abs(A1e[i] - (m div 2)) + Abs(T1o[i] - (m - (m div 2))) + A1o[i] + T1e[i] >
         Abs(T1e[i] - (m div 2)) + Abs(A1o[i] - (m - (m div 2))) + A1e[i] + T1o[i]) else
                          FirstIsFirst := (Abs(G1e[i] - (m div 2)) + Abs(C1o[i] - (m - (m div 2))) + G1o[i] + C1e[i] >
         Abs(C1e[i] - (m div 2)) + Abs(G1o[i] - (m - (m div 2))) + G1e[i] + C1o[i]);
      For j := 1 to m do
      begin
        If (i mod 2 = 1) then
        begin
          If (FirstIsFirst) xor not(j mod 2 = 1) then OutPutField[i, j] := ('A') else OutPutField[i, j] := ('T');
        end else
        BEgin
          If (FirstIsFirst) xor not(j mod 2 = 1) then OutPutField[i, j] := ('G') else OutPutField[i, j] := ('C');
        end;
      end;
    end;
  end;
  If GC1 = minimum Then
  begin
    For i := 1 To n do
    begin
      If i mod 2 = 1 Then FirsTIsFirsT := (abs(G1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + G1o[i] + C1e[i] >
         abs(C1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + G1e[i] + C1o[i]) else
                          FirsTIsFirsT := (abs(A1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + A1o[i] + T1e[i] >
         abs(T1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + T1o[i]);
      For j := 1 To m do
      begin
        If (i mod 2 = 1) Then
        begin
          If (FirsTIsFirsT) xor not(j mod 2 = 1) Then OutputField[i, j] := ('G') else OutputField[i, j] := ('C');
        end else
        begin
          If (FirsTIsFirsT) xor not(j mod 2 = 1) Then OutputField[i, j] := ('A') else OutputField[i, j] := ('T');
        end;
      end;
    end;
  end;
  If GT1 = minimum then
  begin
    For i := 1 to n do
    begin
      If i mod 2 = 1 then firstisfirst := (abs(G1e[i] - (m div 2)) + abs(T1o[i] - (m - (m div 2))) + G1o[i] + T1e[i] >
         abs(T1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + G1e[i] + T1o[i]) else
                          firstisfirst := (abs(A1e[i] - (m div 2)) + abs(C1o[i] - (m - (m div 2))) + A1o[i] + C1e[i] >
         abs(C1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + C1o[i]);
      For j := 1 to m do
      begin
        If (i mod 2 = 1) then
        begin
          If (firstisfirst) xor not(j mod 2 = 1) then OutputField[i, j] := ('G') else OutputField[i, j] := ('T');
        end else
        begin
          If (firstisfirst) xor not(j mod 2 = 1) then OutputField[i, j] := ('A') else OutputField[i, j] := ('C');
        end;
      end;
    end;
  end;
  If CT1 = minimum then
  begin
    For i := 1 to n do
    begin
      If i mod 2 = 1 then FirstIsFirst := (Abs(C1e[i] - (m div 2)) + Abs(T1o[i] - (m - (m div 2))) + C1o[i] + T1e[i] >
         Abs(T1e[i] - (m div 2)) + Abs(C1o[i] - (m - (m div 2))) + C1e[i] + T1o[i]) else
                          FirstIsFirst := (abs(A1e[i] - (m div 2)) + abs(G1o[i] - (m - (m div 2))) + A1o[i] + G1e[i] >
         abs(G1e[i] - (m div 2)) + abs(A1o[i] - (m - (m div 2))) + A1e[i] + G1o[i]);
      For j := 1 to m do
      begin
        If (i mod 2 = 1) then
        begin
          If (FirstIsFirst) xor not(j mod 2 = 1) then OutputField[i, j] := ('C') else OutputField[i, j] := ('T');
        end else
        begin
          If (FirstIsFirst) xor not(j mod 2 = 1) then OutputField[i, j] := ('A') else OutputField[i, j] := ('G');
        end;
      end;
    end;
  end;
  //
  If AG2 = minimum then
  begin
    For j := 1 to m do
    begin
      if j mod 2 = 1 then FirstIsFirst := (abs(A2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + A2o[j] + G2e[j] >
         abs(G2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + G2o[j]) else
                          FirstIsFirst := (abs(C2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + C2o[j] + T2e[j] >
         abs(T2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + C2e[j] + T2o[j]);
      For i := 1 to n do
      begin
        If (j mod 2 = 1) then
        begin
          If (FirstIsFirst) xor not(i mod 2 = 1) then OutputField[i, j] := ('A') else OutputField[i, j] := ('G');
        end else
        begin
          If (FirstIsFirst) xor not(i mod 2 = 1) then OutputField[i, j] := ('C') else OutputField[i, j] := ('T');
        end;
      end;
    end;
  end;
  If AC2 = minimum Then
  begin
    For j := 1 to m do
    begin
      If j mod 2 = 1 Then FirsTIsFirsT := (Abs(A2e[j] - (n div 2)) + Abs(C2o[j] - (n - (n div 2))) + A2o[j] + C2e[j] >
         Abs(C2e[j] - (n div 2)) + Abs(A2o[j] - (n - (n div 2))) + A2e[j] + C2o[j]) else
                          FirsTIsFirsT := (Abs(G2e[j] - (n div 2)) + Abs(T2o[j] - (n - (n div 2))) + G2o[j] + T2e[j] >
         Abs(T2e[j] - (n div 2)) + Abs(G2o[j] - (n - (n div 2))) + G2e[j] + T2o[j]);
      For i := 1 to n do
      begin
        If (j mod 2 = 1) Then
        begin
          If (FirsTIsFirsT) xor not(i mod 2 = 1) Then OutputField[i, j] := ('A') else OutputField[i, j] := ('C');
        end else
        begin
          If (FirsTIsFirsT) xor not(i mod 2 = 1) Then OutputField[i, j] := ('G') else OutputField[i, j] := ('T');
        end;
      end;
    end;
  end;
  If AT2 = minimum then
  begin
    For j := 1 to m do
    begin
      If j mod 2 = 1 then FirstIsFirst := (Abs(A2e[j] - (n div 2)) + Abs(T2o[j] - (n - (n div 2))) + A2o[j] + T2e[j] >
         Abs(T2e[j] - (n div 2)) + Abs(A2o[j] - (n - (n div 2))) + A2e[j] + T2o[j]) else
                          FirstIsFirst := (Abs(G2e[j] - (n div 2)) + Abs(C2o[j] - (n - (n div 2))) + G2o[j] + C2e[j] >
         Abs(C2e[j] - (n div 2)) + Abs(G2o[j] - (n - (n div 2))) + G2e[j] + C2o[j]);
      For i := 1 to n do
      begin
        If (j mod 2 = 1) then
        begin
          If (FirstIsFirst) xor not(i mod 2 = 1) then OutputField[i, j] := ('A') else OutputField[i, j] := ('T');
        end else
        begin
          If (FirstIsFirst) xor not(i mod 2 = 1) then OutputField[i, j] := ('G') else OutputField[i, j] := ('C');
        end;
      end;
    end;
  end;
  If GC2 = minimum Then
  begin
    For j := 1 to m do
    begin
      If j mod 2 = 1 Then FirsTIsFirsT := (abs(G2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + G2o[j] + C2e[j] >
         abs(C2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + G2e[j] + C2o[j]) else
                          FirsTIsFirsT := (abs(A2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + A2o[j] + T2e[j] >
         abs(T2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + T2o[j]);
      For i := 1 to n do
      begin
        If (j mod 2 = 1) Then
        begin
          If (FirsTIsFirsT) xor not(i mod 2 = 1) Then OutputField[i, j] := ('G') else OutputField[i, j] := ('C');
        end else
        begin
          If (FirsTIsFirsT) xor not(i mod 2 = 1) Then OutputField[i, j] := ('A') else OutputField[i, j] := ('T');
        end;
      end;
    end;
  end;
  If GT2 = minimum then
  begin
    For j := 1 to m do
    begin
      If j mod 2 = 1 then firstisfirst := (abs(G2e[j] - (n div 2)) + abs(T2o[j] - (n - (n div 2))) + G2o[j] + T2e[j] >
         abs(T2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + G2e[j] + T2o[j]) else
                          firstisfirst := (abs(A2e[j] - (n div 2)) + abs(C2o[j] - (n - (n div 2))) + A2o[j] + C2e[j] >
         abs(C2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + C2o[j]);
      For i := 1 to n do
      begin
        If (j mod 2 = 1) then
        begin
          If (firstisfirst) xor not(i mod 2 = 1) then OutputField[i, j] := ('G') else OutputField[i, j] := ('T');
        end else
        begin
          If (firstisfirst) xor not(i mod 2 = 1) then OutputField[i, j] := ('A') else OutputField[i, j] := ('C');
        end;
      end;
    end;
  end;
  If CT2 = minimum then
  begin
    For j := 1 to m do
    begin
      If j mod 2 = 1 then FirstIsFirst := (Abs(C2e[j] - (n div 2)) + Abs(T2o[j] - (n - (n div 2))) + C2o[j] + T2e[j] >
         Abs(T2e[j] - (n div 2)) + Abs(C2o[j] - (n - (n div 2))) + C2e[j] + T2o[j]) else
                          FirstIsFirst := (abs(A2e[j] - (n div 2)) + abs(G2o[j] - (n - (n div 2))) + A2o[j] + G2e[j] >
         abs(G2e[j] - (n div 2)) + abs(A2o[j] - (n - (n div 2))) + A2e[j] + G2o[j]);
      For i := 1 to n do
      begin
        If (j mod 2 = 1) then
        begin
          If (FirstIsFirst) xor not(i mod 2 = 1) then OutputField[i, j] := ('C') else OutputField[i, j] := ('T');
        end else
        begin
          If (FirstIsFirst) xor not(i mod 2 = 1) then OutputField[i, j] := ('A') else OutputField[i, j] := ('G');
        end;
      end;
    end;
  end;
  For i := 1 to n do
  begin
    For j := 1 to m do
    begin
      Write(OutPutField[i, j]);
    end;
    WriteLn;
  end;
  ReadLn;
end.